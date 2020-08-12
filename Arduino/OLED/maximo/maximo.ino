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
  
  oled.print("Texto en amarillo ocupa dos lineas,16 px");
  oled.setCursor(10,16);
  oled.print("hola, este texto ya esta en la zona de color cyan y entran 6 lineas en total, mucha informacion en poco espacio");
  oled.display();
  
}
