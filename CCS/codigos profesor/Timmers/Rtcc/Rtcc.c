#include <16f877a.h>
#fuses XT,NOWDT,NOPROTECT,PUT,BROWNOUT 
#use delay(clock=4000000)              // Velocidad del Cristal : 4 Mhz

byte const n=30;                   // Numero de interrupciones para 1 Segundo
char k=0;                         // Contador de Interrupciones ocurridas

#int_RTCC                              // Interrupción por desbordamiento
RTCC_isr() {                           // del TIMER0 RTCC
if(k > n){                  // Si las ints ocurridas > ints para 1 Seg.
output_toggle(PIN_B0); 
k=0;}
++k;                            // Incremento el número de interrupciones
}                                      // Ocurridas

void main(void) {
setup_counters(RTCC_INTERNAL,RTCC_DIV_128);// TIMER0: Clock Interno, Presescaler 128
setup_timer_1(T1_DISABLED);                // para una RTCC cada 33.3 milisegundos
setup_timer_2(T2_DISABLED,0,1);            // -> 1 Segundo = 30 RTCC
setup_comparator(NC_NC_NC_NC);
setup_vref(FALSE);
enable_interrupts(INT_RTCC);               // Habilito Interrupción RTCC
enable_interrupts(global);                 // Habilito Interrupciones
set_tris_b(0x00); //configura RB0 como salida el resto igual
output_b(0x00); 

While(1);
}

