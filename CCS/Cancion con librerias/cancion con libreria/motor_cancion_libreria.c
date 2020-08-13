#include<18f452.h>
#fuses nowdt,xt,NOPROTECT
#use delay(clock=4M)
#INCLUDE<math.h>
#include<tones.c>
#include <lcd.c>
boolean cancion1=false,cancion2=false;
int contador=0,CONTAM=0;
Void menu ();
void gir_iz ();
void gir_der ();
void giro_hacia (int num);
int giro=0;
int conta=0,conta2=0;
int contagiros=0,temreal=0;
int i,cambio=0;
boolean empezar=false;
boolean flag=true;
int pos1=0,pos2=0;
#INT_TIMER1
void movimientimer(){
contador++;
if(contador==6){
CONTAM++;
switch (CONTAM){
case 1:
output_b(0x80);
break;
case 2:
output_b(0x40);
break;
case 3:
output_b(0x20);
break;
case 4:
output_b(0x10);
break;
case 5:
CONTAM=0;
break;
}contador=0;}
set_timer1(65223);
}
 
void gir_izq(void){
   while(conta<10){
    lcd_gotoxy(1,1);
    printf(lcd_putc," elija num de \n segundos");
    if(flag==true){
    if(input(pin_a1)==1){
      contagiros++;
      lcd_gotoxy(11,2);
    printf(lcd_putc,"%i\n",contagiros);
      if(contagiros==60){
       lcd_gotoxy(11,2);
     printf(lcd_putc,"   ");
      contagiros=1;}
      delay_ms(90);  
     if(input(pin_a1)==0){
    flag=false;
    }}
    }
   
   if(flag==false){
   int tiempo=ceil(contagiros/0.4);
   if(input(pin_a1)==1){
       delay_ms(100);
       if(input(pin_a1)==0){
        setup_timer_1 ( T1_INTERNAL | T1_DIV_BY_8 ); // RESOLUCION DEL TIMER 1/((20MHz/4)/8)=3,2uS
        enable_interrupts(INT_TIMER1);
       enable_interrupts(GLOBAL); // SE HABILITAN LAS INTERRUPCIONES GLOBALES
       cancion1=true;
        LCD_PUTC("\f");
       printf(lcd_putc,"Girando");
      if (cancion1==true){
for(int i=0;i<contagiros;i++){
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
       pos1=0;
       cancion1=false;
        conta=11;
       empezar=false;
       }}
       
    // disable_interrupts(INT_TIMER1);
       }}//cont2=11;
    }}

void gir_der(void){
       while(conta2<10){
    lcd_gotoxy(1,1);
    printf(lcd_putc," elija num de \n segundos");
    if(flag==true){
    if(input(pin_a2)==1){
      contagiros++;
      lcd_gotoxy(11,2);
    printf(lcd_putc,"%i\n",contagiros);
      if(contagiros==60){
       lcd_gotoxy(11,2);
     printf(lcd_putc,"   ");
      contagiros=0;}
      delay_ms(100);  
     if(input(pin_a2)==0){
    flag=false;
    }}
    }
   
   if(flag==false){
   int tiempo2=ceil(contagiros/0.4);
   if(input(pin_a2)==1){
       delay_ms(100);
       if(input(pin_a2)==0){
       setup_timer_1 ( T1_INTERNAL | T1_DIV_BY_8 ); // RESOLUCION DEL TIMER 1/((20MHz/4)/8)=3,2uS
       enable_interrupts(INT_TIMER1); 
       enable_interrupts(GLOBAL); // SE HABILITAN LAS INTERRUPCIONES GLOBALES
       cancion2=true;
       LCD_PUTC("\f");
       printf(lcd_putc,"Girando");
       lcd_gotoxy(1,2);
       printf(lcd_putc,"time: %i\n",tiempo2);
     if (cancion2==true){
 for(int i=0;i<contagiros;i++){
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
     pos2=0;
       empezar=false;
       conta2=11;
       cancion2=false;
}}
   
       }}
   }}


void main(){
   set_tris_a(0x0f);
    lcd_init();
    

 for(int i=30;i>0;i--){
        LCD_PUTC("\f");
        lcd_gotoxy(i-15,1);//columnas,filas
        printf(lcd_putc,"Bienvenidos");
        delay_ms(1);}
        delay_ms(1);
 WHILE(true)
      {
      if(empezar==false){
        lcd_gotoxy(0,1);//columnas,filas
        printf(lcd_putc," Pulse giro \n  A=izq  B=der ");
        if(input(pin_a1)==1){
         delay_ms(100);
         if(input(pin_a1)==0){
        LCD_PUTC("\f");
        empezar=true;
        giro=1;}}
        if(input(pin_a2)==1){
        delay_ms(100); 
        If(input(pin_a2)==0){
        LCD_PUTC("\f");
        empezar=true;
        giro=2;}}}
if(empezar==true){        
switch (giro){
      case 1: 
       lcd_gotoxy(1,1);
       printf(lcd_putc,"giro izquierda");
       delay_ms(200);
           conta=0;
           contagiros=0;
           flag=true;
           cancion1=false;
       gir_izq();
       
       break;
      case 2:
       lcd_gotoxy(1,1);
       printf(lcd_putc,"giro derecha");
       delay_ms(200);
       conta2=0;
           contagiros=0;
           flag=true;
           cancion2=false;
       gir_der();
           
       break;
}}}}

