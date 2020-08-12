#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO 64
#define OLED_RESET 4
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET); 




void setup() {
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() {
  oled.clearDisplay();
 for(int i=1; i<  oled.height()*1.5;i++){
    oled.drawCircle(oled.width()/2, oled.height()/2, i, WHITE);
    oled.drawCircle(oled.width()/2, oled.height()/2, i-15, WHITE);
    oled.drawCircle(oled.width()/2, oled.height()/2, i-30, WHITE);
    oled.display();
    delay(50);
    oled.clearDisplay();
  }
  
    oled.drawRect(0,0,127,15,WHITE);
    oled.setCursor(10,3 );
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.print("La Temperatura es:");
    oled.setCursor(40,30 );
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.print("35.72C");
    oled.display();
    
 
    delay(10000);
    
    
    
   
    

   
    
  
  
} 
