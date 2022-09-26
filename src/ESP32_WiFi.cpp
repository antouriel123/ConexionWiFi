#include <Arduino.h>
#include <WiFi.h>
#include <EEPROM.h>
#include "ESP32_WiFi.h"

void WiFi_STA(void)
{
  //Sacamos la clave y el nombre del SSID de la memoria EEPROM
  SSID_2=EEPROM.readString(addressSSID);
  PASSWORD_2=EEPROM.readString(addressPASSWORD);
  //Iniciamos la conexion con la RED local 
  Serial.println(SSID_2);
  Serial.println(PASSWORD_2);
  WiFi.begin(SSID_2.c_str(),PASSWORD_2.c_str());
  //ahora verificamos la conexion de la red
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
    Serial.print("STA direccion IP:");
  Serial.println(WiFi.localIP());
}

void WiFi_AP(void)
{
  //Establecemos el modo estacion y access point
  WiFi.mode(WIFI_AP_STA);
  //Escribimos en el puerto serial 
  Serial.println("\nConfiguramos el WiFi access point");
  WiFi.softAP(SSID_1,PASSWORD_1);
  //Imprimimos el siguiente mensaje 
  Serial.println("¡¡WiFi listo!!");  
  Serial.print("Este es el nombre de la RED: ");
  Serial.println(SSID_1);
  Serial.print("Contraseña: ");
  Serial.println(PASSWORD_1); 
  Serial.println(WiFi.softAPIP());
}
