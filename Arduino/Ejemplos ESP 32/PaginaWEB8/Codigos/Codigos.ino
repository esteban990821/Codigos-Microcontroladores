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
            // Estas lineas de codigo indican que se trabaja en un entorno HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            // Este es el contenido de la página WEB en lenguaje HTML
            client.print("<head>");
            client.print("<title>Universidad Distrital Francisco Jose de Caldas</title>");
            client.print("</head>");
            client.println("<body>");
            client.print("<h1>Codigos</h1>");
            client.print("<a href=Codigo_Pic(CCS)_Comunicacion_Serial.html>Codigo Pic(CCS) Comunicacion Serial</a>");
            client.println("<br>");  
            client.println("</body>");  
         
            
            // Indicación de que termina la página WEB:
            client.println();
            // Terminar Bucle.
            break;
          } 
          else{          
            //Limpiar buffer en caso de que no haya información de llegada
            RespuestaCliente = "";
          }
        } 
      }
    }
    // Terminar conexión con el cliente:
    client.stop();
    Serial.println("Cliente Desconectado.");
  }
}
