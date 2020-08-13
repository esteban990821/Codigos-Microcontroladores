///////////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                           ////
////  Ejemplo de comunicacion USB entre PIC y PC                                               ////
////                                                                                           ////
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <18F4550.h>
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
#use delay(clock=48000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// CCS Library dynamic defines.  For dynamic configuration of the CCS Library
// for your application several defines need to be made.  See the comments
// at usb.h for more information
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#define USB_HID_DEVICE     FALSE             // deshabilitamos el uso de las directivas HID
#define USB_EP1_TX_ENABLE  USB_ENABLE_BULK   // turn on EP1(EndPoint1) for IN bulk/interrupt transfers
#define USB_EP1_RX_ENABLE  USB_ENABLE_BULK   // turn on EP1(EndPoint1) for OUT bulk/interrupt transfers
#define USB_EP1_TX_SIZE    32                // size to allocate for the tx endpoint 1 buffer
#define USB_EP1_RX_SIZE    32                // size to allocate for the rx endpoint 1 buffer

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Include the CCS USB Libraries.  See the comments at the top of these
// files for more information
//
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <pic18_usb.h>                      // Microchip PIC18Fxx5x Hardware layer for CCS's PIC USB driver
#include ".\include\rr2_USB_Monitor.h"      // Configuración del USB y los descriptores para este dispositivo
#include <usb.c>        	                 // handles usb setup tokens and get descriptor reports

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Defines y otras zarandajas
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#define LED_VERDE    PIN_E0
#define LED_AMARILLO PIN_E1
#define LED_ROJO     PIN_E2

#define Enciende     Output_High
#define Apaga        Output_Low
#define Conmuta      Output_Toggle

#define RecCommand   recbuf[0]

#define COMMAND_LED          1
#define COMMAND_FIRMWARE     2
#define COMMAND_STRING_RS232 3

const int8 Lenbuf = 32;

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// RAM, RAM, RAM
//
///////////////////////////////////////////////////////////////////////////////////////////////////

char Version[] = "v.1.0";
int  i;

int8 recbuf[Lenbuf];
int8 sndbuf[Lenbuf];

///////////////////////////////////////////////////////////////////////////////////////////////////
//
// M A I N
//
///////////////////////////////////////////////////////////////////////////////////////////////////

void main(void) {

   delay_ms(500);

   printf("RRUSB By Redpic %s\r\n",Version);

   Apaga(LED_VERDE);
   Apaga(LED_AMARILLO);
   Enciende(LED_ROJO);

   delay_ms(100);

   printf("USB Mon : usb_init()\r\n");
   usb_init();

   printf("USB Mon : usb_task()\r\n");
   usb_task();

   printf("USB Mon : usb_wait_for_enumeration()\r\n");
   usb_wait_for_enumeration();


   enable_interrupts(global);

   printf("USB Mon : while(TRUE)\r\n");
   while (TRUE)
   {
      if(usb_enumerated())
      {
         Apaga(LED_ROJO);
         Enciende(LED_VERDE);
         if (usb_kbhit(1))
         {
            printf("USB Mon : usb_kbhit()\r\n");
            // Recibe Packet
            usb_get_packet(1, recbuf, Lenbuf);
            printf("USB Mon : usb_get_packet()\r\n");
            // Comando : Conmuta LED
            if(RecCommand==COMMAND_LED){
               printf("USB Mon : Conmuta(LED_AMARILLO)\r\n");
               Conmuta(LED_AMARILLO);
            }
            // Comando : Transmite Version
            if(RecCommand==COMMAND_FIRMWARE){
               printf("USB Mon : usb_put_packet(%s)\r\n",Version);
               usb_put_packet(1,Version,6,USB_DTS_TOGGLE);
            }
            // Comando : Escribe String en RS232
            if(RecCommand==COMMAND_STRING_RS232){
               printf("USB Mon : String_2_RS232(%s)\r\n",recbuf);
               printf("%s\r\n",recbuf);
            }
         }
      }
      else{
         Apaga(LED_VERDE);
         Enciende(LED_ROJO);
      }
   }
}
