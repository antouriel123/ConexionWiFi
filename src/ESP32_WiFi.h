#ifndef _ESP32_WiFi_H_
#define _ESP32_WiFi_H_

/*     DECLARACION DE MACROS Y CONSTANTES     */
static const char *SSID_1 = "DEV1_ESP32";             //Nombre y clave de la red creada por el ESP32
static const char *PASSWORD_1 = "4179Volframio";
#define EEPROM_SIZE 100
#define addressSSID 0
#define addressPASSWORD 50
#define LED_STATE 2

/*     VARIABLES GLOBALES     */
static String SSID_2;
static String PASSWORD_2;


/*     DECLARACION DE PROTOTIPOS DE FUNCION     */
extern void WiFi_STA(void);
extern void WiFi_AP(void);

#endif /*_ESP32_WiFi_H_*/