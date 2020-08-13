#include <16F877a.h>
#fuses XT,NOWDT
#use delay(clock= 4M)
#include<tones.c>
int a,b,c;
void main(void){

 while(true){
   if (input(PIN_A0)==1){
   a=1;
   b=0;
   c=0;
   }
 
   if (input(PIN_A1)==1){
   b=1;
   a=0;
   c=0;
   }
    
   if (input(PIN_A2)==1){
   c=1;
   b=0;
   a=0;
   }

   if ((input(PIN_A3)==1)&( a==1)){
  generate_tone(F_NOTE[1] ,250);
generate_tone(G_NOTE[1] ,250);
generate_tone(A_NOTE[1] ,250);
generate_tone(F_NOTE[1] ,250); 
generate_tone(C_NOTE[1] ,750);
generate_tone(A_NOTE[1] ,250);
generate_tone(G_NOTE[1] ,500);
generate_tone(F_NOTE[1] ,250);
generate_tone(D_NOTE[1] ,250); 
generate_tone(A_NOTE[1] ,750); 
generate_tone(F_NOTE[1] ,250); 
generate_tone(E_NOTE[1] ,1000);
generate_tone(F_NOTE[1] ,250); 
generate_tone(E_NOTE[1] ,250); 
generate_tone(D_NOTE[1] ,500); 
generate_tone(E_NOTE[1] ,500); 
generate_tone(F_NOTE[1] ,250); 
generate_tone(G_NOTE[1] ,250); 
generate_tone(C_NOTE[1] ,500); 
generate_tone(F_NOTE[1] ,500); 
generate_tone(G_NOTE[1] ,250); 
generate_tone(A_NOTE[1] ,250);
generate_tone(Bb_NOTE[1] ,500);
   }  

if ((input(PIN_A3)==1)&( b==1)){
generate_tone(G_NOTE[1] ,500);
generate_tone(F_NOTE[1] ,500);
generate_tone(E_NOTE[1] ,500);
generate_tone(F_NOTE[1] ,1500); 
generate_tone(D_NOTE[1] ,500);
generate_tone(F_NOTE[1] ,500);
generate_tone(A_NOTE[1] ,500);
generate_tone(D_NOTE[2] ,1000);
generate_tone(D_NOTE[2] ,500);
generate_tone(D_NOTE[2] ,500); 
generate_tone(C_NOTE[2] ,500); 
generate_tone(B_NOTE[1] ,500);
generate_tone(C_NOTE[2] ,500); 
generate_tone(E_NOTE[2] ,1000); 
generate_tone(D_NOTE[2] ,500); 
generate_tone(C_NOTE[2] ,500); 
generate_tone(B_NOTE[1] ,500); 
generate_tone(C_NOTE[2] ,500); 
generate_tone(D_NOTE[1] ,1000);
generate_tone(C_NOTE[2] ,500); 
generate_tone(B_NOTE[1] ,1000); 
generate_tone(A_NOTE[1] ,500);
}
if ((input(PIN_A3)==1)&( c==1)){


 
generate_tone(C_NOTE[2] ,750);
generate_tone(C_NOTE[2] ,250);
generate_tone(E_NOTE[2] ,750);
generate_tone(C_NOTE[2] ,750); 
generate_tone(B_NOTE[1] ,500);
generate_tone(A_NOTE[1] ,1000);
generate_tone(G_NOTE[1] ,1000);
generate_tone(C_NOTE[2] ,750);
generate_tone(C_NOTE[2] ,250);
generate_tone(E_NOTE[2] ,750);
generate_tone(C_NOTE[2] ,750);
generate_tone(B_NOTE[1] ,500);

 delay_ms(500);

generate_tone(A_NOTE[1] ,1000);
generate_tone(G_NOTE[1] ,1000);
generate_tone(C_NOTE[2] ,750);
generate_tone(C_NOTE[2] ,250);
generate_tone(E_NOTE[2] ,750);
generate_tone(C_NOTE[2] ,750);
generate_tone(B_NOTE[1] ,500);
generate_tone(A_NOTE[1] ,1000);
generate_tone(G_NOTE[1] ,1000);
}
 }}
