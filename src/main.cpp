#include <Arduino.h>
#include <EEPROM.h>
#include <SPIFFS.h>
#include "ESP32_WiFi.h"
#include "Server.h"

void setup() {
  //Configuramos el puerto serial a una velocidad de 19200
  Serial.begin(19200);
  SPIFFS.begin();
  //Inicia con el espacio asignado 
  EEPROM.begin(EEPROM_SIZE);
  //Iniciamos con la configuracion del modo AP para primero guardar los dato de la RED
  if(!digitalRead(0))
  {
    //Borramos el contenido asignado en la memoria EEPROM
    for(uint16_t i=0;i<100;i++)
    {
    EEPROM.write(i,0);
    }
    WiFi_AP();
    //Inicializa el servidor 
    InitServer();
  }
  else{
    //Inicia la
    WiFi_STA();
  }
}

void loop() {   
}