/////////////////////////////////////////////////////////////////////////
////                                                                 ////
//// RR2_USB_Cdc_Monitor.c                                           ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////

#include <18F4550.h>
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
#use delay(clock=48000000)

#include ".\include\usb_cdc.h"

#rom int 0xf00000={1,2,3,4}

void main() {
   BYTE i, j, address, value;

   delay_ms(300);
   usb_cdc_init();
   usb_init();
   while(!usb_cdc_connected()) {}

   do {
      usb_task();
      if (usb_enumerated()) {
         printf(usb_cdc_putc, "\r\n\nEEPROM:\r\n");              // Display contents of the first 64
         for(i=0; i<=3; ++i) {                     // bytes of the data EEPROM in hex
            for(j=0; j<=15; ++j) {
               printf(usb_cdc_putc, "%2x ", read_eeprom( i*16+j ) );
            }
            printf(usb_cdc_putc, "\n\r");
         }
         printf(usb_cdc_putc, "\r\nLocation to change: ");
         address = gethex_usb();
         printf(usb_cdc_putc, "\r\nNew value: ");
         value = gethex_usb();

         write_eeprom( address, value );
      }
   } while (TRUE);
}
