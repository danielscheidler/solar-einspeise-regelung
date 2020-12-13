/**
 * ---------------------------------------------------------------------------------- 
 * Solar Einspeise Regelung
 * ---------------------------------------------------------------------------------- 
 * Kooperation von Utuberlars und SmartHome yourself
 * 
 * Utuberlars:           https://www.youtube.com/channel/UCWzgOrFuh82znXetsW3pmAA
 *                       https://www.guerilla-stromer.de/
 *                       
 * SmartHome yourself:   https://www.youtube.com/SmartHomeYourselfDe_DIY
 *                       https://smarthomeyourself.de
 * 
 * Platine zum Projekt:  https://www.pcbway.com/project/shareproject/Solar_Einspeise_Regelung.html
 * 
 * Sourcecode:           https://github.com/danielscheidler/solar-einspeise-regelung
 *  
 * Kurzanleitung:        https://smarthomeyourself.de/anleitung-zum-selber-bauen/unabhaengige-projekte/arduino-und-esp-projekte/solar-einspeise-regelung-utuberlars/
 * 
 * ----------------------------------------------------------------------------------
 * 
 * Wenn kein WLAN verbunden werden kann, wird ein offener WLAN-AccessPoint mit dem Namen "UTUBERLARS" gestartet.
 * Auf dieses WLan kann man dann ohne Passwort verbinden und anschliessend im Browser 
 * auf die Adresse: http://192.168.4.1 verbinden. 
 * 
 * Hier lassen sich nun unter Einstellungen die Daten des eigenen WLANs eintragen.
 * 
 * by Daniel Scheidler 2020
 */
#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h> 


/* -------- CONFIG START -------- */

// Maximale WLAN-Verbindungsversuche
# define maxConnectionAttemts  20

// Pinbelegung
#define LED_PIN                D5
#define RELAIS_PIN             D6
#define VOLTAGE_SENSOR_PIN     A0

// Intervall für Spannungsmessung in Millisekunden
int voltageRefreshIntervall = 2000;

/* -------- CONFIG ENDE --------- */

/* ------------------------------ */
/* ! AB HIER NICHTS MEHR ÄNDERN ! */
/* ------------------------------ */

ESP8266WebServer server ( 80 );

void setup() {
  Serial.begin ( 9600 );
  while (!Serial) {
  }
  Serial.println("");
  Serial.println("UTUBERLARS - Einspeise Regelung");
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  pinMode(RELAIS_PIN, OUTPUT);
  digitalWrite(RELAIS_PIN, LOW);
  
  pinMode(VOLTAGE_SENSOR_PIN, INPUT);
 
  loadConfig();

  connectWifi();
  startWebServer();

  Serial.println("");
  Serial.println("Initialized");
  Serial.println("");
}


void loop() {
  server.handleClient();

  checkStates();
  
  refreshStatusLed();
  
  delay(1);
}

void connectWifi(){
  char* ssid = getSsid();

  WiFi.hostname(getWifiHostname());
  WiFi.begin (ssid, getWifiPassword());
  int connectionAttemts = 0;
  
  while ( WiFi.status() != WL_CONNECTED ) {
    if(connectionAttemts > maxConnectionAttemts){
      break;
    }
    delay ( 500 ); 
    Serial.print ( "." );
    connectionAttemts++;
  }
  

  Serial.println ( "" ); 
  
  if(WiFi.status() == WL_CONNECTED){
    Serial.print ( "Connected to " ); Serial.println ( ssid );
    Serial.print ( "IP address: " ); Serial.println ( WiFi.localIP() );
  } else {
    WiFi.disconnect(true);

    delay(100);
    hostWifiAP();  
  }

  Serial.println ( "" ); 
}

void hostWifiAP(){
  Serial.print("Starte AccessPoint: ");
  Serial.println(WiFi.softAP(getApName()) ? "OK" : "Fehler!");

  Serial.print("AccessPoint IP: ");
  Serial.println(WiFi.softAPIP());
}

void startWebServer(){
  server.on ( "/", handleRoot );
  server.on ( "/admin", handleAdmin );
  server.on ( "/calibrate", handleCalibrate );

  server.begin();
  Serial.println ( "HTTP server started" );
}
