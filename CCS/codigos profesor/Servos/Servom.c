#include <16F877A.h>
#device adc=8
#FUSES HS,NOWDT,NOPROTECT,NOLVP
#define SERVOUT PIN_B0
#use delay(clock=20M)

int8 valor;
int16 pulse;

void servo();

void main(void){
setup_adc_ports(ra0_analog);
setup_adc(adc_clock_internal);
set_adc_channel(0);
while (1){
valor=read_adc();
servo();}
}


void servo(){
int i;
for (i = 0; i < 50; i++){
output_high (SERVOUT);
pulse=(int16) 6*valor+500;
delay_us(pulse);
output_low (SERVOUT);
delay_ms(18);
}
}
