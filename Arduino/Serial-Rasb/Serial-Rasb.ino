const int analogPin = A0;

int value;      //variable que almacena la lectura analógica raw

void setup() {

Serial.begin(9600);

}

void loop() {
value = analogRead(analogPin);      
  Serial.print(value);
   delay(500);
  Serial.print("\n");
 
  

}
