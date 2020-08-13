#include <16F887.h>//Pic utilizado
#FUSES NOWDT, HS, NOPUT, NOMCLR, NOPROTECT, NOCPD, NOBROWNOUT, NOIESO, NOFCMEN, NOLVP, NODEBUG, NOWRT, BORV40
#use delay(clock=4000000)
#bit RB0=0x06.0 //Identificador para el bit RB7



#int_TIMER1

void TIMER1_isr(void){

RB0=~RB0;

set_timer1(0x0BDC);

}


void main(){

set_tris_b(0x00); //configura RB7 como salida el resto como entrada
output_b(0x00); 
RB0=0;//Inicializo RB7
setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);//Setup timer: Reloj interno, preescaler= 8
enable_interrupts(INT_TIMER1);//Habilito interrupción particular del TIMER1
enable_interrupts(GLOBAL);//Habilito interrupciones globales

set_timer1(0x0BDC);//Carga del TMR1
while(true);//Bucle infinito hasta interrupción
}

