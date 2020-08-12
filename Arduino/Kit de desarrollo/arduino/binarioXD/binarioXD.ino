int tiempo=400;
int tiempo2=200;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
}
void secuencia_OFF(){
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_B0(){
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_B1(){
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
}
void secuencia_B2(){
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_B3(){
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
}
void secuencia_B4(){
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_B5(){
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
}
void secuencia_B6(){
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
}
void secuencia_B7(){
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
}
void secuencia_B8(){
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_B9(){
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
}
void secuencia_B10(){
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
}
void secuencia_B11(){
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
}
void secuencia_B12(){
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_B13(){
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
}
void secuencia_B14(){
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
}
void secuencia_B15(){
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
secuencia_B0();
secuencia_B1();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B2();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B3();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B4();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B4();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B5();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B6();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B7();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B8();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B9();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B10();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B11();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B12();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B13();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B14();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_B15();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
}
