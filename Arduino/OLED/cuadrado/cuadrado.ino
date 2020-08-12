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
  
    oled.drawRect(20,20,88,44,WHITE);
    oled.setCursor(28, 34);
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.print("ALARMA");
    oled.display();
  
  
  
} 
