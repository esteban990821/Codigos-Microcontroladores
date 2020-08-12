int pwm=100;
int a=3,b=7,c=4;
void setup() {
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(c,HIGH);
digitalWrite(b,LOW);
analogWrite(a,250);
}
