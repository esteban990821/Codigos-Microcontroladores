#INCLUDE <18f4550.H>
#FUSES  XT, NOWDT, NOLVP
#USE DELAY (CLOCK= 2000000)

#USE STANDARD_IO(D)
#USE STANDARD_IO(B)
int i,a,d,b,c;


void main (void){
set_tris_a(0xff);


while(true){

if(input(PIN_A0)==1){
a=1;
c=0;
b=0;
}
if(input(PIN_A1)==1){
b=1;
c=0;
a=0;
}
if(input(PIN_A2)==1){
c=1;
b=0;
a=0;
}
if(input(PIN_A3)==1){
d=1;
}

if((a==1)&&(d==1))

{
output_low(PIN_D3);
delay_ms(100);

while(1)
{

for(i=0;i<60;i++){
output_high(PIN_D3);
delay_us(0);
output_low(PIN_D3);
delay_ms(10);
}
delay_us(100);

for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(150);
output_low(PIN_D1);
delay_ms(10);
}

delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1157);
output_low(PIN_D0);
delay_ms(10);
}

delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(520);
output_low(PIN_D1);
delay_ms(10);
}

delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}

delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(800);
output_low(PIN_D1);
delay_ms(10);
}

delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1157);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(1157);
output_low(PIN_D1);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
}
}

if((b==1)&&(d==1))

{
output_low(PIN_D3);
delay_ms(100);

while(1)
{
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(0);
output_low(PIN_D1);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);


for(i=0;i<60;i++){
output_high(PIN_D3);
delay_us(578);
output_low(PIN_D3);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1000);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(400);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1000);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(400);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1000);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(400);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(800);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(500);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1000);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(400);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
}

}

if((c==1)&&(d==1))

{

output_low(PIN_D3);
delay_ms(100);

while(1)
{
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(0);
output_low(PIN_D1);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);


for(i=0;i<60;i++){
output_high(PIN_D3);
delay_us(578);
output_low(PIN_D3);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1157);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1157);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D1);
delay_us(1157);
output_low(PIN_D1);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1157);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(1157);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);
for(i=0;i<60;i++){
output_high(PIN_D0);
delay_us(0);
output_low(PIN_D0);
delay_ms(10);
}
delay_us(100);


}
}

}}
