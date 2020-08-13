#include <16f877a.h> 

#device adc=10
#include <stdio.h>
#fuses XT,NOWDT,NOLVP,PUT,BROWNOUT
#use delay (clock=4M)
#use rs232 (baud=9600, parity=N, xmit=pin_c6, rcv=pin_c7, bits=8)

char dato;

#int_rda
void rda_isr(){
   dato=getc();
    
    switch(dato){
      
      case '1': output_high(pin_A0);
         break;
      case '2': output_low(pin_A0);
         break;
      case '3': output_high(pin_A1);
         break;
      case '4': output_low(pin_A1);
         break;
      case '5': output_high(pin_A2);
         break;
      case '6': output_low(pin_A2);
         break;
      case '7': output_high(pin_A3);
         break;
      case '8': output_low(pin_A3);
         break;
       case '9': output_high(pin_B4);
         break;
      case 'a': output_low(pin_B4);
         break;
      case 'c': output_high(pin_B6);
         break;
      case 'd': output_low(pin_B6);
         break;
      case 'e': output_high(pin_B5);
         break;
      case 'f': output_low(pin_B5);
         break;
       case 'b': output_high(pin_B3);
         break;
      case 's': output_low(pin_B3);
         break;
      case '+': output_high(pin_B2);
         break;
      case '-': output_low(pin_B2);
         break;
      case 'x': output_high(pin_B1);
         break;
      case 'z': output_low(pin_B1);
         break;
       case 'w': output_high(pin_A5);
         break;
      case 'v': output_low(pin_A5);
         break;
      
         
       
    }
}

void main(){

enable_interrupts(int_rda);
enable_interrupts(global);
   
   while (true){
  
         
   }
    
   
}
