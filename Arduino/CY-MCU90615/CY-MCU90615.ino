#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
unsigned char output[33];
unsigned char need[2];
int value=0;
void setup() {
  Serial.begin(57600);
  pinMode(3, INPUT);
  while(!Serial){
    ;  
  }
  mySerial.begin(115200);
  mySerial.write(0xA5);
  mySerial.write(0x45);
  mySerial.write(0xEA);
}

void loop() {
  if(mySerial.available()){
    Serial.print("Taking Readings");
    for(int counter=0;counter<=32;counter++){
      output[counter] = (unsigned char)mySerial.read();
      Serial.print(".");
    } delay(100);
    for(int obj=0;obj<=32;obj++){
      if(output[obj]==0x5A){
        need[0] = output[obj+4];
        need[1] = output[obj+5];
        float temp = (float)(need[0] << 8 | need[1])/100;
        float TO=temp;
        delay(1);
        float TA=temp;
        if(TO>=0&&TO<50){
        Serial.println();
        Serial.println("Temperature is: ");
        Serial.print(TA);
         delay(1);}
      } 
        
      else{//No need to do anything}  
    }
    
    }
  }
}
