#include <16f877a.h>
#fuses XT,NOWDT,NOPUT
#use delay(clock=20M)
#use standard_io(E) 
#use standard_io(A) 

#include <lcd.c>

void main()
 {
    lcd_init(); 
        for(int i=20;i>0;i--){
        LCD_PUTC("\f");
        lcd_gotoxy(i,1);//columnas,filas
        printf(lcd_putc,"Bienvenidos");
        delay_ms(150);}
    
while(1){
        lcd_gotoxy(0,1);//columnas,filas
        printf(lcd_putc," Pulse giro \n  A=izq  B=der ");
} 
}
