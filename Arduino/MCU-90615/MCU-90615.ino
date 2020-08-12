unsigned char Re_buf[11],counter=0;
unsigned char sign=0;
float TO=0,TA=0;
void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(115200);
  delay(1);
  Serial.write(0XA5);
  Serial.write(0X45);
  Serial.write(0XEA);
}
 
void loop() {
  unsigned char i=0,sum=0;
 digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(50); 
  if(sign)
  {
     sign=0;
     for(i=0;i<8;i++)
      sum+=Re_buf[i];
     if(sum==Re_buf[i] )
     {
           TO=(float)(Re_buf[4]<<8|Re_buf[5])/100;
           Serial.print("TO:");
           Serial.println(TO);
           TA=(float)(Re_buf[6]<<8|Re_buf[7])/100;
           Serial.print("TA:");
           Serial.println(TA);
   }
  }
 
}
void serialEvent() {
  while (Serial.available()) {
    Re_buf[counter]=(unsigned char)Serial.read();
    if(counter==0&&Re_buf[0]!=0x5A) return;
    counter++;
    if(counter==9)
    {
       counter=0;
       sign=1;
    }
  }
}
