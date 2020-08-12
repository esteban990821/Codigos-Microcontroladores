
const int sensorPin = A0;    // seleccionar la entrada para el sensor
int sensorValue;       // variable que almacena el valor raw (0 a 1023)
 
void setup()
{
   Serial.begin(9600);
}
 
void loop() 
{
   sensorValue = analogRead(sensorPin);   // realizar la lectura
 
   //mandar mensaje a puerto serie en función del valor leido
 
   
      Serial.println(sensorValue);
   
    
   
   delay(100);
}
