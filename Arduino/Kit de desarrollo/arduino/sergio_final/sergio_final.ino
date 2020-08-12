int tiempo=400;
int tiempo2=200;
int pin;
int brillo;
const int led=(13,12,11,10);
const int pot=0;
#include <Keypad.h> 
#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const byte ROWS = 4; //four rows
const byte COLS = 4; //FOUR columns
char keys[ROWS][COLS] = {
  {'1','2','N','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 
void setup(){
  for(pin =10; pin <= 13;pin++ )
  {
  Serial.begin(9600);
  pinMode(pin,OUTPUT);
}

{pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(led, OUTPUT);}
{ lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MILLONARIOS F.C...."); // Mensaje a despegar
  delay(3000);}
}
void secuencia_leds2(){
  digitalWrite(13,HIGH);
  delay(tiempo2);
  digitalWrite(12,HIGH);
  delay(tiempo2);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
   digitalWrite(10,HIGH);
  delay(tiempo2);
  digitalWrite(11,HIGH);
  delay(tiempo2);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
void secuencia_leds(){
 for(pin =10; pin <= 13;pin++ )
 {
  digitalWrite(pin,HIGH);
  delay(tiempo2);
  digitalWrite(pin,LOW);  
  delay(tiempo2);
 }
for(pin =13; pin >= 10;pin-- )
 {
  digitalWrite(pin,HIGH);
  delay(tiempo2);
  digitalWrite(pin,LOW);  
  delay(tiempo2);
 }
}
void secuencia_apagado(){
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
void secuencia_lcd1(){
 for(int c=0;c<12;c++){
  lcd.scrollDisplayLeft();
  delay(400);
  }
  }
void secuencia_lcd2(){
  for(int c=0; c<12;c++){
  lcd.scrollDisplayRight();
  delay(400); 
  }}
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

   void secuencia_uno() {
  // put your main code here, to run repeatedly:
 for(pin =10; pin <= 13;pin++ )
 {
  digitalWrite(pin,HIGH);
  delay(tiempo2);
  digitalWrite(pin,LOW);  
  delay(tiempo2);
 }
}
 void secuencia_dos() {
  // put your main code here, to run repeatedly:
 for(pin =13; pin >= 10;pin-- )
 {
  digitalWrite(pin,HIGH);
  delay(tiempo2);
  digitalWrite(pin,LOW);  
  delay(tiempo2);
 }
 }
void loop(){
  char key = keypad.getKey();
   
  if (key){
    Serial.println(key);
  }
  delay(10);

if(key == '2'){
secuencia_uno();
}

if(key == '5'){
secuencia_dos();
}
if(key == '8'){
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
if(key == '0'){
secuencia_lcd1();
}
if(key == 'N'){
secuencia_lcd2();
}
if(key == '6'){
 secuencia_leds2();
 secuencia_leds2();
 secuencia_leds2();
 secuencia_leds2();
 secuencia_leds2();
 secuencia_leds2();
 secuencia_leds2();
 secuencia_leds2();
}
if (key== '9'){
  secuencia_leds();
  secuencia_leds();
  secuencia_leds();
  secuencia_leds();
  secuencia_leds();
  secuencia_leds();
  secuencia_leds();
}
if(key == '#'){
  digitalWrite(13,HIGH);
}
if(key == 'A'){
  digitalWrite(12,HIGH);
}
if(key == 'B'){
  digitalWrite(11,HIGH);
}
if(key == 'C'){
  digitalWrite(10,HIGH);
}
if(key == 'D'){
secuencia_apagado();
}
{brillo = analogRead(pot)/4;
analogWrite(led, brillo);
}
}

