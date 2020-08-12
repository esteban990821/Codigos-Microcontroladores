#include <Wire.h>

#define SLAVE_ADDRESS 0x04//direccion esclavo
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
int variable = 0;
void setup() {
pinMode(13, OUTPUT);
Serial.begin(9600); // start serial for output
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

Serial.println("11Ready!");
}

void loop() {
  delay(100);
}
// callback for received data
void receiveData(int byteCount){

while(Wire.available()) {
variable = Wire.read();
Serial.print("data received: ");
Serial.println(variable);
}
}

// callback for sending data
void sendData(){
sensorValue=analogRead(analogInPin);
Wire.write(sensorValue);
}
