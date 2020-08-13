#include <16f877a.h> 
#device adc=10
//#include <stdio.h>
#fuses XT,NOWDT,NOLVP,PUT,BROWNOUT
#use delay (clock=4M)
#use rs232 (baud=9600, parity=N, xmit=pin_c6, rcv=pin_c7, bits=8)

// LCD
#define lcd_rs_pin pin_C0
#define lcd_rw_pin pin_C1
#define lcd_enable_pin pin_C2
#define lcd_data4 pin_A0
#define lcd_data5 pin_A1
#define lcd_data6 pin_A2
#define lcd_data7 pin_A3

// columnas 
# define col1 pin_B0
# define col2 pin_b1
# define col3 pin_b2
# define col4 pin_b3
# define col5 pin_b4
# define col6 pin_b5
# define col7 pin_b6
# define col8 pin_b7

#include <lcd.c>
#include <math.h>
//#use standard_io (C)

// pacman LCD y MUN 

char mun [8] ={
   0b01110,
   0b10101,
   0b10101,
   0b11111,
   0b11111,
   0b10101,
   0b10101,
   0b00000,
}; 
char  pacman1 [8] ={
   0b01110,
   0b11011,
   0b11111,
   0b11000,
   0b11000,
   0b11111, 
   0b01111,
   0b00000,
};
char pacman [8]={
   0b01110,
   0b11011,
   0b11111,
   0b11111,
   0b11111,
   0b11111,
   0b01111,
   0b00000,
};


char dato , dato2 , Fila1 = 0x00 , Fila2 = 0x00 , Fila3 = 0x00 , Fila4 = 0x00 ;
char Fila5 = 0x00 , Fila6 = 0x00 , Fila7 = 0x00 , Fila8 = 0x00 ;
int barrido[]={0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};

int vector0[8];
int mov[];
int modo = 0 , contador = 0 , e , l; 


#int_rda
void serial_isr(){

dato=getc();

if (dato == 0xA8) {
  output_E(0b00000001);
  modo = 1 ;
 for(e = 0 ; e < 1 ; e++){
    
    Lcd_gotoxy(1,1);
    printf(lcd_putc,"Comunicacion on ");
    Lcd_gotoxy(3,2);
    printf(lcd_putc," Dibujando %c ",17);
  }
   l = 0 ; 
}
else if (dato == 0xA9) {
  output_E(0b00000010);
  modo = 0 ;     
 for(l = 0 ; l < 1 ; l++){ 
    Lcd_gotoxy(1,1);
    printf(lcd_putc,"Comunicacion off ");
    Lcd_gotoxy(4,2);
    printf(lcd_putc," Escaneando ");
 }
 e = 0 ; 
}
if(modo == 1) {
 switch(dato){
      case 0x31 : 
        output_E(0b00000001);
        Fila1 = Fila1 + 0x01; 
         break;
      case 0x32 : 
        Fila1 = Fila1 - 0x01;
         break;
      case 0x33 : 
        Fila1 = Fila1 + 0x02;
         break;
      case 0x34 : 
        Fila1 = Fila1 - 0x02;
         break;
      case 0x35 :
        Fila1 = Fila1 + 0x04;
         break;
      case 0x36 :
        Fila1 = Fila1 - 0x04;
         break;
      case 0x37 :
        Fila1 = Fila1 + 0x08;
         break;
      case '8':
        Fila1 = Fila1 - 0x08;
         break;
      case '9':
        Fila1 = Fila1 + 0x10;
         break;
      case 'a':
        Fila1 = Fila1 - 0x10;
         break;
      case 'b':
        Fila1 = Fila1 + 0x20;
         break;
      case 'c':
        Fila1 = Fila1 - 0x20;
         break;
      case 'd':
        Fila1 = Fila1 + 0x40;
         break;
      case 'e':
        Fila1 = Fila1 - 0x40;
         break;
      case 'f':
        Fila1 = Fila1 + 0x80;
         break;
      case 'g':
        Fila1 = Fila1 - 0x80;
         break;
      case 'h': 
        Fila2 = Fila2 + 0x01; 
         break;
      case 'i': 
        Fila2 = Fila2 - 0x01; 
         break;
      case 'j': 
        Fila2 = Fila2 + 0x02; 
         break;
      case 'k':
        Fila2 = Fila2 - 0x02; 
         break;
      case 'l': 
        Fila2 = Fila2 + 0x04; 
         break;
      case 'm':
         Fila2 = Fila2 - 0x04; 
         break;
      case 'n': 
         Fila2 = Fila2 + 0x08; 
         break;
      case 'o': 
         Fila2 = Fila2 - 0x08;
         break;
      case 'p':
         Fila2 = Fila2 + 0x10;
         break;
      case 'q': 
         Fila2 = Fila2 - 0x10;
         break;
       case 'r': 
         Fila2 = Fila2 + 0x20;
         break;
      case 's': 
         Fila2 = Fila2 - 0x20;
         break;
       case 't': 
         Fila2 = Fila2 + 0x40;
         break;
       case 'u': 
         Fila2 = Fila2 - 0x40;
         break;
      case 'v': 
         Fila2 = Fila2 + 0x80;
         break;
      case 'w': 
         Fila2 = Fila2 - 0x80;  
         break;
       case 'x':
         Fila3 = Fila3 + 0x01;  
         break;
      case 'y': 
         Fila3 = Fila3 - 0x01;  
         break; 
       case 'z': 
         Fila3 = Fila3 + 0x02;  
         break;
      case 'A': 
         Fila3 = Fila3 - 0x02;  
         break;  
       case 'B': 
         Fila3 = Fila3 + 0x04;  
         break;
      case 'C': 
         Fila3 = Fila3 - 0x04;  
         break;    
       case 'D': 
         Fila3 = Fila3 + 0x08;  
         break;
      case 'E': 
         Fila3 = Fila3 - 0x08;    
         break;
       case 'F': 
         Fila3 = Fila3 + 0x10;
         break;
      case 'G': 
         Fila3 = Fila3 - 0x10;
         break;  
       case 'H': 
         Fila3 = Fila3 + 0x20;
         break;
      case 'I': 
         Fila3 = Fila3 - 0x20;
         break;   
       case 'J': 
         Fila3 = Fila3 + 0x40;
         break;
      case 'K': 
         Fila3 = Fila3 - 0x40;
         break;
       case 'L': 
         Fila3 = Fila3 + 0x80;
         break;
      case 'M': 
         Fila3 = Fila3 - 0x80;
         break;  
       case 'N': 
         Fila4 = Fila4 + 0x01;
         break;
      case 'O': 
         Fila4 = Fila4 - 0x01;
         break;
       case 'P': 
         Fila4 = Fila4 + 0x02;
         break;
      case 'Q': 
         Fila4 = Fila4 - 0x02;
         break;
      case 'R': 
         Fila4 = Fila4 + 0x04;
         break;
      case 'S': 
         Fila4 = Fila4 - 0x04;
         break;
      case 'T': 
         Fila4 = Fila4 + 0x08;
         break;
      case 'U': 
         Fila4 = Fila4 - 0x08;
         break;
      case 'V': 
         Fila4 = Fila4 + 0x10;
         break;
      case 'W': 
         Fila4 = Fila4 - 0x10;
         break;
       case 'X': 
         Fila4 = Fila4 + 0x20;
         break;
      case 'Y': 
         Fila4 = Fila4 - 0x20;
         break;
      case 'Z': 
         Fila4 = Fila4 + 0x40;
         break;
      case '?': 
         Fila4 = Fila4 - 0x40;
         break; 
      case ']': 
         Fila4 = Fila4 + 0x80;
         break;
      case '[': 
         Fila4 = Fila4 - 0x80;
         break;
      case '!': 
         Fila5 = Fila5 + 0x01;
         break;
      case '%': 
         Fila5 = Fila5 - 0x01;
         break;
      case '<': 
         Fila5 = Fila5 + 0x02;
         break;
      case '>': 
         Fila5 = Fila5 - 0x02;
         break; 
       case '}': 
         Fila5 = Fila5 + 0x04;
         break;
      case '{': 
         Fila5 = Fila5 - 0x04;
         break;
      case ')': 
         Fila5 = Fila5 + 0x08;
         break;
      case '(': 
         Fila5 = Fila5 - 0x08;
         break;
     case '/': 
         Fila5 = Fila5 + 0x10;   
         break;
     case '$': 
         Fila5 = Fila5 - 0x10;   
         break;
     case '&': 
         Fila5 = Fila5 + 0x20;   
         break;
     case '=': 
         Fila5 = Fila5 - 0x20;   
         break;
     case '+': 
         Fila5 = Fila5 + 0x40;
         break;
     case '-': 
         Fila5 = Fila5 - 0x40;
         break;
     case '*': 
         Fila5 = Fila5 + 0x80;
         break;
     case '^': 
         Fila5 = Fila5 - 0x80;
         break;
     case '|': 
         Fila6 = Fila6 + 0x01;
         break;
     case ',': 
        Fila6 = Fila6 - 0x01;
        break;
     case ';': 
        Fila6 = Fila6 + 0x02;
        break;
     case ':': 
        Fila6 = Fila6 - 0x02; 
        break;
     case '.': 
        Fila6 = Fila6 + 0x04;
        break;
     case '@': 
        Fila6 = Fila6 - 0x04;
        break;
     case '0': 
        Fila6 = Fila6 + 0x08;
        break;
     case '~': 
        Fila6 = Fila6 - 0x08;
        break;
    }
    switch(dato){
      case 0x80 : 
         Fila6 = Fila6 + 0x10;
         break;
      case 0x81 : 
         Fila6 = Fila6 - 0x10;
         break;
      case 0x82 : 
         Fila6 = Fila6 + 0x20;
         break;
      case 0x83 : 
         Fila6 = Fila6 - 0x20;
         break;
      case 0x84 : 
         Fila6 = Fila6 + 0x40;
         break;
      case 0x85 : 
         Fila6 = Fila6 - 0x40;
         break;
      case 0x86 : 
         Fila6 = Fila6 + 0x80;
         break;
      case 0x87 : 
         Fila6 = Fila6 - 0x80;
         break;
      case 0x88 : 
         Fila7 = Fila7 + 0x01;
         break;
      case 0x89 : 
         Fila7 = Fila7 - 0x01;
         break;
      case 0x8A : 
         Fila7 = Fila7 + 0x02;
         break;
      case 0x8B : 
         Fila7 = Fila7 - 0x02;
         break;
      case 0x8C : 
         Fila7 = Fila7 + 0x04;
         break;
      case 0x8D : 
         Fila7 = Fila7 - 0x04;
         break;
      case 0x8E : 
         Fila7 = Fila7 + 0x08;
         break;
      case 0x8F : 
         Fila7 = Fila7 - 0x08;
         break;
      case 0x90 : 
         Fila7 = Fila7 + 0x10;
         break;
      case 0x91 : 
         Fila7 = Fila7 - 0x10;
         break;
      case 0x92 : 
         Fila7 = Fila7 + 0x20;
         break;
      case 0x93 : 
         Fila7 = Fila7 - 0x20;
         break;
      case 0x94 : 
         Fila7 = Fila7 + 0x40;
         break;
      case 0x95 : 
         Fila7 = Fila7 - 0x40;
         break;
      case 0x96 : 
         Fila7 = Fila7 + 0x80;
         break;
      case 0x97 : 
         Fila7 = Fila7 - 0x80;
         break; 
      case 0x98 : 
         Fila7 = Fila7 + 0x01;
         break;
      case 0x99 : 
         Fila8 = Fila8 - 0x01;
         break;
      case 0x9A : 
         Fila8 = Fila8 + 0x02;
         break;
      case 0x9B : 
         Fila8 = Fila8 - 0x02;
         break;
      case 0x9C : 
         Fila8 = Fila8 + 0x04;
         break;
      case 0x9D : 
         Fila8 = Fila8 - 0x04;
         break;
      case 0x9E : 
         Fila8 = Fila8 + 0x08;
         break;
      case 0x9F : 
         Fila8 = Fila8 - 0x08;
         break;
      case 0xA0 : 
         Fila8 = Fila8 + 0x10;
         break;
      case 0xA1 : 
         Fila8 = Fila8 - 0x10;
         break;
      case 0xA2 : 
         Fila8 = Fila8 + 0x20;
         break; 
      case 0xA3 : 
         Fila8 = Fila8 - 0x20;
         break; 
      case 0xA4 : 
         Fila8 = Fila8 + 0x40;
         break; 
      case 0xA5 : 
         Fila8 = Fila8 - 0x40;
         break; 
      case 0xA6 : 
         Fila8 = Fila8 + 0x80;
         break; 
      case 0xA7 : 
         Fila8 = Fila8 - 0x80;
         break; 
    }
  }
}
void main(){


   set_tris_b(0x00);// columnas como salida 
   set_tris_d(0x00);// filas como salidas

enable_interrupts(int_rda);
enable_interrupts(global);

//output_E(0b00000011);
int  pac , i , posc , move , move2 ;
//item=0;
//port_b_pullups(true);
lcd_init();
//kbd_init();
lcd_clear(1);

lcd_set_Cgram_char(0 , mun);
lcd_set_Cgram_char(1 , pacman1);
lcd_set_Cgram_char(2 , pacman);

for (int intro = 0 ; intro < 1 ; intro++) {

output_b(0b00000000);
output_d(0b00000000);

    Lcd_gotoxy(4,1);
    printf(lcd_putc,"Encendiendo");
    Lcd_gotoxy(8,2);
    printf(lcd_putc," %c ",0);
    delay_ms(5000);   
    Lcd_gotoxy(33,33);
   
for ( pac = 1 , posc = 1 , i = 17 ; i > 1 ; --i ){ 
    printf(lcd_putc," %c " , 2 );
    lcd_gotoxy(pac , posc );
    delay_ms(150);
    printf(lcd_putc," %c " , 1 );
    lcd_gotoxy(pac , posc );
    delay_ms(200);
      ++pac;
        if( (i < 3)  &&  (posc == 1) ){
            i = 17 ;
            posc = 2;
            pac = 1 ;
        }
  }
    lcd_clear(1);
for( move = 17 ;move > 1 ; --move ){
  lcd_gotoxy(move,1);
  printf(lcd_putc," Matrix  ");
  delay_ms(250);
}
for( move2 = 1 ; move2 < 5 ; ++move2 ){
  lcd_gotoxy(move2 ,2);
  printf(lcd_putc," Proyection ");
  delay_ms(250);
 }
}


for(contador=0;contador<500;contador++){
  
output_d(Fila1);
output_high(col1);
delay_ms(1);
output_low(col1);

output_d(Fila2);
output_high(col2);
delay_ms(1);
output_low(col2);

output_d(Fila3);
output_high(col3);
delay_ms(1);
output_low(col3);

output_d(Fila4);
output_high(col4);
delay_ms(1);
output_low(col4);

output_d(Fila5);
output_high(col5);
delay_ms(1);
output_low(col5);

output_d(Fila6);
output_high(col6);
delay_ms(1);
output_low(col6);

output_d(Fila7);
output_high(col7);
delay_ms(1);
output_low(col7);

output_d(Fila8);
output_high(col8);
delay_ms(1);
output_low(col8);
 
  }
}


  
