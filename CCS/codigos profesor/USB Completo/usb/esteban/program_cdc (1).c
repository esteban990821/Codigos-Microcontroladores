////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                  COMUNICACI�N PIC 18F4550 - PC POR USB                     //
//                Clase de dispositivo CDC USB emulando RS232                 //
//                           Ing. Frank Giraldo                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
#include <18F4550.h>             
#device adc=8;  
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
#use delay(clock=20000000)    
#define  USB_CONFIG_PID      0x000B 
#define  USB_CONFIG_VID      0x04D8
#include <usb_cdc.h>             

unsigned int val_adc;         
char c;                      


void main() {  
setup_adc_ports(AN0);         //Definici�n del pin a utilizar como entrada anal�gica
setup_adc(ADC_CLOCK_INTERNAL);//Definici�n de la fuente de reloj para el A/D
set_adc_channel(0);           //Selecci�n del canal anal�gico
set_tris_b(0x00);   
usb_cdc_init();               //Inicializaci�n del modo CDC
usb_init();                   
   
do{
usb_task();                //Detecci�n de la conexi�n de dispositivo USB
      if (usb_enumerated()) {    
         val_adc=read_adc();
         printf(usb_cdc_putc, "\f Valor = %u", val_adc);  //escribe puerto usb val adc sensor    
         if (usb_cdc_kbhit()){         
            c=usb_cdc_getc();  //lee puerto usb
            if (c=='h') {output_high(pin_b0);}
            if (c=='l') {output_low(pin_b0);}}
         delay_ms(100);
      }
   } while (TRUE);
}
