float temperatura, valor_adc; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int LM35 = 0; // Variable del pin de entrada del sensor (A0)
 
void setup() {
  // Cambiamos referencia de las entradas analógicas
  analogReference(INTERNAL);
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
}
 
void loop() {
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  valor_adc = analogRead(LM35); 
   
  // Calculamos la temperatura con la fórmula
  temperatura= (1.1 * valor_adc  * 100.0)/1024.0; 
 
  // Envia el dato al puerto serial
  Serial.print(temperatura);
  // Salto de línea
  Serial.print("\n");
  
  // Esperamos un tiempo para repetir el loop
  delay(200);
}
