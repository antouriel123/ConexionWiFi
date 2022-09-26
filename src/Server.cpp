/*     DIRECTIVAS DEL PROGRAMA     */
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <EEPROM.h>
#include "ESP32_WiFi.h"
#include "server.h"

/*     DECLARACION DE TIPOS DE DATOS     */
AsyncWebServer servidor(80);

void GuardarDatosWiFi(AsyncWebServerRequest *request)
{
  //Variables locales
  String SSID_2;
  String PASSWORD_2;
  //Escribimos un mensaje en el puerto serial comprobando que funciona la llamada de peticiones
  Serial.println("¡¡Peticion Recibida del navegador!!");
  
  //Se guardan los datos enviado por el formulario
  SSID_2=request->arg("SSID");
  PASSWORD_2=request->arg("PASSWORD");
  //Imprime para verificar que si se acepto 
  Serial.println(request->arg("SSID"));
  Serial.println(request->arg("PASSWORD"));
  //Ahora guardamos el dato de obtenido en el formulario en la memoria EEPROM
  EEPROM.writeString(addressSSID,SSID_2);
  EEPROM.writeString(addressPASSWORD,PASSWORD_2);
  EEPROM.commit();
  //respondemos al cliente
  request->send(200,"text/plain","Guardado la clave de red!!");
  //Reiniciamos el ESP32 para ver si se guardaron los datos 
  ESP.restart();
}

void InitServer(void)
{
	servidor.serveStatic("/", SPIFFS, "/").setDefaultFile("formulario.html");

  servidor.on("/DatosWiFi",HTTP_POST,GuardarDatosWiFi);

	servidor.onNotFound([](AsyncWebServerRequest *request) {
		request->send(400, "text/plain", "Not found");
	});

	servidor.begin();
	Serial.println("HTTP server started");
}