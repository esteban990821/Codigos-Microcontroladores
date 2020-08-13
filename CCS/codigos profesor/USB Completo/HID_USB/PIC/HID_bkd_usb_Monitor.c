/////////////////////////////////////////////////////////////////////////
////                                                                 ////
////  rr2_HID_kbd_usb_Monitor.c                                      ////
////                                                                 ////
////  by RedPic                                                      ////
////                                                                 ////
////  08/10/2006                                                     ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////

#include <18F4550.h>
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
#use delay(clock=20000000)

#DEFINE USB_HID_DEVICE  TRUE

#define USB_EP1_TX_ENABLE  USB_ENABLE_INTERRUPT   //turn on EP1 for IN bulk/interrupt transfers
#define USB_EP1_TX_SIZE 8

#define USB_EP1_RX_ENABLE  USB_ENABLE_INTERRUPT   //turn on EP1 for IN bulk/interrupt transfers
#define USB_EP1_RX_SIZE 8

#include <pic18_usb.h>
#include <.\include\usb_kbd_HID.h>               //USB Configuration and Device descriptors for this UBS device
#include <usb.c>                                 //handles usb setup tokens and get descriptor reports
#include <ctype.h>

/////////////////////////////////////////////////////////////////////////////
//
// Defines y Zarandajas
//
/////////////////////////////////////////////////////////////////////////////

#define LED1    PIN_E0
#define LED2    PIN_E1
#define LED3    PIN_E2

#define LED_ON  output_high
#define LED_OFF output_low

#define PIN_SOURCE PIN_B1

/////////////////////////////////////////////////////////////////////////////
//
// RAM
//
/////////////////////////////////////////////////////////////////////////////

int8 connected;
int8 enumerated;
int8 rx_msg[USB_EP1_RX_SIZE];
int8 tx_msg[8]={2,0,0,0,0,0,0,0};

char NextChar='0';
int1 hay_dato=0;

int8 i;

/////////////////////////////////////////////////////////////////////////////
//
// usb_debug_task()
//
// When called periodically, displays debugging information over serial
// to display enumeration and connection states.  Also lights LED2 and LED3
// based upon enumeration and connection status.
//
/////////////////////////////////////////////////////////////////////////////

void usb_debug_task(void) {

   enumerated=usb_enumerated();

   if(enumerated){
      LED_ON(LED1);
      LED_OFF(LED3);
   }
   else{
      LED_ON(LED3);
      LED_OFF(LED1);
   }
}

/////////////////////////////////////////////////////////////////////////////
//
// usb_keyboard_task()
//
// Sends a packet of keyboard data.  The protocol was specified in the HID
// report descriptor (see usb_desc_kbmouse.h), and is:
//     tx_msg[0]   = HID report id (2)
//     tx_msg[1]   = modifier (an 8bit bitmap of shift, tab, alt keypress)
//     tx_msg[2]   = const 0
//     tx_msg[3:7] = an array of held down keys.  a=4, b=5, etc.
//                   if msg[2:7]={0} then no keys are held down
//
//     rx_msg[1] = HID report id (2)
//     rx_msg[0] = 5bit bitmap of led status
//
/////////////////////////////////////////////////////////////////////////////

int8 char_2_usb_kbd_code(char c){

   int8 ic;

   if(isAlpha(c)){
      ic=c-'a'+4;
   }
   else{
      if(c=='0'){
        ic=39;
      }
      else{
        ic=c-'1'+30;
      }
   }
   return(ic);
}

void usb_keyboard_task(void) {

   static char Char_Tx;

   if(hay_dato==1){

      hay_dato=0;
      tx_msg[3]=char_2_usb_kbd_code(NextChar);
      usb_put_packet(1,tx_msg,sizeof(tx_msg),USB_DTS_TOGGLE);
      
      ++NextChar;
      if(NextChar>'z'){
         NextChar='0';
      }
      if(NextChar>'9'&&NextChar<'a'){
         NextChar='a';
      }
      LED_OFF(LED2);
      delay_ms(5);

   }else{

      tx_msg[3]=0;
      usb_put_packet(1,tx_msg,sizeof(tx_msg),USB_DTS_TOGGLE);
      delay_ms(5);

   }
}


/////////////////////////////////////////////////////////////////////////////
//
// usb_rx_task()
//
// Listens to EP1 for any incoming packets.  The only report ID that is
// configurd to send us data is 2 (keyboard LED status, see above)
//
/////////////////////////////////////////////////////////////////////////////

void usb_rx_task(void){

   if (usb_kbhit(1)){
      usb_get_packet(1, rx_msg, sizeof(rx_msg));
   }
}

/////////////////////////////////////////////////////////////////////////////
//
// recibe por interrupción ext
//
/////////////////////////////////////////////////////////////////////////////

#int_ext
void ext_handler(void){

   if(hay_dato==0){
     hay_dato=1;
     LED_ON(LED2);
   }
}

void main() {

   hay_dato=0;

   delay_ms(500);

   LED_OFF(LED1);
   LED_OFF(LED2);
   LED_OFF(LED3);

   usb_init_cs();

   port_b_pullups(true);
   set_tris_b(0b00000001);
   output_high(PIN_SOURCE);
   ext_int_edge(0,L_TO_H);
   enable_interrupts(int_ext);
   enable_interrupts(global);

   while (TRUE) {

      usb_task();
      usb_debug_task();

      if (usb_enumerated()) {
         usb_keyboard_task();
         usb_rx_task();
         delay_ms(5);
      }
   }
}

