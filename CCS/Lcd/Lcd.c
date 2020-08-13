
#include <18f4550.h>
#fuses XT,NOWDT,NOPROTECT
#use delay(clock= 4M)
#INCLUDE <LCD.C>

int a,b,c;

void main(){
 LCD_INIT(); 
 
 while(true){
 set_tris_A(0xff);

 
 
  if(input(pin_a1)==1){
 
  

    LCD_PUTC("\f");
   output_high(pin_c0);
    lcd_gotoxy(1,1);
 printf(LCD_putc," DIGIELECTROS \n set fotografico  ");
 delay_ms(750);
 LCD_PUTC("\f");
  lcd_gotoxy(1,1);
 printf(LCD_putc," Seleccione una \n figura y color:  ");
 
 }
 
 
  if(input(pin_a2)==1){
    LCD_PUTC("\f");
   output_high(pin_c0);
    lcd_gotoxy(1,1);
 printf(LCD_putc," Seleccion: \n Fig: DOMO   ");
 a=1;
 b=0;
 c=0;
  }
   if(input(pin_a3)==1){
     LCD_PUTC("\f");
    lcd_gotoxy(1,1);
 printf(LCD_putc," Seleccion: \n Fig: LUNA  ");
 a=0;
 b=1;
 c=0;
 
  }
  if(input(pin_a4)==1){
   LCD_PUTC("\f");
    lcd_gotoxy(1,1);
 printf(LCD_putc,"Seleccion:  \n Fig: CIRCULOS ");
 a=0;
 b=0;
 c=1;
  }
   if((input(pin_a5)==1)&(a==1)&(b==0)&(c==0)){
 for(int i=15;i>0;i--){
        LCD_PUTC("\f");
        lcd_gotoxy(1,1);//columnas,filas
        printf(lcd_putc,"Fig: DOMO");
        lcd_gotoxy(i,2);//columnas,filas
        printf(lcd_putc,"Iniciando....");
        delay_ms(300);}
  }
  
    if((input(pin_a5)==1)&(a==0)&(b==1)&(c==0)){
 for(int i=15;i>0;i--){
        LCD_PUTC("\f");
        lcd_gotoxy(1,1);//columnas,filas
        printf(lcd_putc,"Fig: LUNA");
        lcd_gotoxy(i,2);//columnas,filas
        printf(lcd_putc,"Iniciando....");
        delay_ms(300);}
  }

    if((input(pin_a5)==1)&(a==0)&(b==0)&(c==1)){
 for(int i=15;i>0;i--){
        LCD_PUTC("\f");
        lcd_gotoxy(1,1);//columnas,filas
        printf(lcd_putc,"Fig: CIRCULOS");
        lcd_gotoxy(i,2);//columnas,filas
        printf(lcd_putc,"Iniciando....");
        delay_ms(300);}
  }
  
 }}
