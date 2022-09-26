#include <Arduino.h>
#include <WiFi.h>
#include <EEPROM.h>
#include "ESP32_WiFi.h"

void WiFi_STA(void)
{
  char SS[50];
  char PW[50];
  //LeerEEPROM();
  SSID_2 = EEPROM.readString(addressSSID);
  
  PASSWORD_2 = EEPROM.readString(addressPASSWORD);

  
  //Establecemos el modo estacion y access point
  WiFi.mode(WIFI_STA);
  //Inicializamos la conexion con la red del ESP32
  //WiFi.softAP(SSID_1,PASSWORD_1);
  
  SSID_2.toCharArray(SS,SSID_2.length());
  PASSWORD_2.toCharArray(PW,PASSWORD_2.length());
  Serial.println(SS);
  Serial.println(PW);
  //Iniciamos la conexion con la RED local 
  WiFi.begin(SS,PW);
  //ahora verificamos la conexion de la red
  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  //Autoreconeccion
  WiFi.setAutoReconnect(true);
  //Escribimos en el puerto serial 
  Serial.println("WiFi Conectado!!");
  Serial.println();
  WiFi.printDiag(Serial);
  Serial.println();
  Serial.print("STA direccion IP:");
  Serial.println(WiFi.localIP());
}

void WiFi_AP(void)
{
  //Establecemos el modo estacion y access point
  WiFi.mode(WIFI_AP);
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

void LeerEEPROM(void)
{
  
}
