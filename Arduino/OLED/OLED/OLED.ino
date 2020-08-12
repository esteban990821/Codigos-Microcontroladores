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
  oled.setTextColor(WHITE); 
  oled.setCursor(0,0);
  oled.setTextSize(2);
  oled.print("22/04/2020");
  oled.setCursor(10,30);
  oled.setTextSize(2);
  oled.print(millis()/1000);
  oled.print(" seg.");
  oled.display();
  

}
