/*Libreria WIFI del IDE de ARDUINO*/
#include <WiFi.h>
//Defina la red y la contraseña del router que 
//le permite establecer la conexión.
const char* ssid  = "Esteban";
const char* clave = "wifi990821";
//Definir el puerto de conexión del servidor.
WiFiServer server(80);
//Inicialización del mircrocontrolador.
void setup()
{
    //Iniciar puerto serial del arduino.
    Serial.begin(115200);
    //Asignar pin 13 (D13) como salida
    pinMode(13, OUTPUT);
    pinMode(14,INPUT);
    delay(10);
    //Mostrar aviso de estableciendo conexión.
    Serial.print("Conectando a: ");
    Serial.println(ssid);
    //Estructura para intentar conectar al ROUTER
    WiFi.begin(ssid, clave);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    //Avisos de finalización
    delay(500);
    Serial.println("Conectado");
    Serial.print("Dirección IP asignada: ");
    Serial.println(WiFi.localIP());
    //Iniciar servidor
    server.begin();
}

void Pagina (WiFiClient client){
  // Estas lineas de codigo indican que se trabaja en un entorno HTML
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  // Este es el contenido de la página WEB en lenguaje HTML
  client.println("<head>");
  client.println("<title>Universidad Distrital Francisco Jose de Caldas</title>");
  //Esta linea permite refrescar la pagina cada 10 segundos.
  client.println("<meta http-equiv=\"refresh\" content=\"10\">");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1> Ejemplo de prender un LED</h1>");
  client.println("<br>");
  client.println("<p = center>");
  client.println("<a href=\"/A\"> Prender</a> </br>");
  client.println("<a href=\"/B\"> Apagar</a> </br>");
  //Si pulse el botón publique encendido en otro caso apagado.
  if(digitalRead(14)){client.println("Encendido </br>");}
  else{client.println("Apagado </br>");}
  //Publicar el valor del ADC
  int sensor=analogRead(36);//El pin 36 es VP
  client.println("Valor ADC= "+(String)sensor+"</br>");
  client.println("</p>");
  client.println("</body>");            
  // Indicación de que termina la página WEB:
  client.println();  
  }

   
void loop(){
  WiFiClient client = server.available();   // Determina si hay nuevos clientes conectados al servidor
  if (client) {                             // Si hay un nuevo cliente continua la rutina
    String RespuestaCliente = "";           // Buffer de la información para almacenar la información que llega
    while (client.connected()) {            // Bucle para mantener la comunicación con el cliente conectado
      if (client.available()) {             // Espera a que el cliente se actualice
        char c = client.read();             // Lectura de la información que llega del cliente
        Serial.write(c);                    // Imprime la información que llega
        if (c == '\n') {                    // Si llega un caracter en blanco 
            // Si hay dos caracteres de salto de linea le indica al cliente que envie los parámetros
            // de la pagina WEB
            if (RespuestaCliente.length() == 0) {
              Pagina(client);
              // Terminar Bucle.
              break;
            } 
            else{          
              //Limpiar buffer en caso de que no haya información de llegada
              RespuestaCliente = "";
            }
          }
          //Esta secuencia le permite al microcontrolador anidar 
          //la palabra que retorna de la pagina
          else if (c != '\r') {  
            RespuestaCliente += c;      
          }
          //Comparación del caracter que llega
          if (RespuestaCliente.endsWith("GET /A")) {
            digitalWrite(13, HIGH);              
          }
          if (RespuestaCliente.endsWith("GET /B")) {
            digitalWrite(13, LOW);                
          } 
      }
    }
    // Terminar conexión con el cliente:
    client.stop();
    Serial.println("Cliente Desconectado.");
  }
}