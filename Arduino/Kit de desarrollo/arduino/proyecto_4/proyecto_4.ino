int tiempo = 100;

int matriz [] = 

int cont = 5;

void setup (){
  for (int pin = 0; pin < contar ; pin++){
    pinMode (matriz [pin], OUTPUT);
  }
}
 void loop() {
  for (int pin = 0; pin < contar ; pin++)
  {
    digitalWrite (matriz [pin] , HIGH);
    delay (tiempo);
    digitalWrite (matriz [pin], LOW);  
  }
  for (int pin = contar -1 ; pin >=0 ; pin--)
  {
    digitalWrite (matriz [pin[, HIGH);
    delay (tiempo);
    digitalWrite (matriz [pin], LOW);
  }
  }

