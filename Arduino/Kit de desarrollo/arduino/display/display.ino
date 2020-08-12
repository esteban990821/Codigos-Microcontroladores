int tiempo=400;
int tiempo2=200;
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}
void secuencia_OFF(){
digitalWrite(8,LOW);
digitalWrite(7,LOW);
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);}
void secuencia_N0(){
digitalWrite(8,HIGH);
digitalWrite(7,HIGH);
digitalWrite(11,HIGH);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(9,HIGH);
}

void secuencia_N1(){
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
}
void secuencia_N2(){
digitalWrite(12,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
}

void secuencia_N3(){
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
digitalWrite(9,HIGH);
digitalWrite(8,HIGH);
}
void secuencia_N4(){
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(13,HIGH);
digitalWrite(11,HIGH);
}

void secuencia_N5(){
digitalWrite(8,HIGH);
digitalWrite(10,HIGH);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(9,HIGH);
}
void secuencia_N6(){
digitalWrite(8,HIGH);
digitalWrite(7,HIGH);
digitalWrite(10,HIGH);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(9,HIGH);
}
void secuencia_N7(){
digitalWrite(13,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);

}
void secuencia_N8(){
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(7,HIGH);
}
void secuencia_N9(){
digitalWrite(10,HIGH);
digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
digitalWrite(13,HIGH);
digitalWrite(12,HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
secuencia_N0();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N1();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N2();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N3();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N4();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N5();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N6();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N7();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N8();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
secuencia_N9();
delay(tiempo);
secuencia_OFF();
delay(tiempo2);
}
