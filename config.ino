// EEPROM Einstellungen
#define CONFIG_VERSION            "ul10"
#define CONFIG_START              0

// Standard Hostname (nicht länger als 13 Zeichen)
#define DEFAULT_WIFI_HOSTNAME     "utl-esr"

// Fallback Wifi-AccessPoint Einstellungen
#define DEFAULT_WIFI_AP_NAME      "UTUBERLARS"

// Schwellwerte für Relais-Schaltung
#define DEFAULT_12V_ON            14.3f
#define DEFAULT_12V_OFF           12.3f
#define DEFAULT_24V_ON            28.8f
#define DEFAULT_24V_OFF           24.8f



struct ConfigStoreStruct {
  char version[5];
  float switchOn12V, switchOff12V, switchOn24V, switchOff24V;
  char ssid[33];
  char wifiPassword[64];
  char wifiHostname[21];
  float voltageFactor;  
};

ConfigStoreStruct configuration = {
  CONFIG_VERSION,
  DEFAULT_12V_ON, 
  DEFAULT_12V_OFF,
  DEFAULT_24V_ON,
  DEFAULT_24V_OFF,
  "",
  "",
  DEFAULT_WIFI_HOSTNAME,
  0.977995f
};

void loadConfig() {
  EEPROM.begin(4096);

  ConfigStoreStruct tmp;
  EEPROM.get(CONFIG_START, tmp);
  delay(10);
  EEPROM.end();

  if(strcmp(tmp.version , CONFIG_VERSION)==0){
    strcpy(configuration.version, tmp.version);
    configuration.switchOn12V = tmp.switchOn12V;
    configuration.switchOff12V = tmp.switchOff12V;
    configuration.switchOn24V = tmp.switchOn24V;
    configuration.switchOff24V = tmp.switchOff24V;
    strcpy(configuration.wifiHostname, tmp.wifiHostname);
    strcpy(configuration.ssid, tmp.ssid);
    strcpy(configuration.wifiPassword, tmp.wifiPassword);
    configuration.voltageFactor = tmp.voltageFactor;

    Serial.println(configuration.voltageFactor);
    Serial.println("Load config OK");
    Serial.print("Version: ");
    Serial.println(configuration.version);
  } else {
    generateHostname();
    saveConfig();
  }
}


void saveConfig() {
  EEPROM.begin(4096);
  EEPROM.put(CONFIG_START, configuration);
  
  if (EEPROM.commit()) {
    Serial.println("Einstellungen gespeichert");
  } else {
    Serial.println("FEHLER beim speichern der Einstellungen!");
  }
  
  EEPROM.end(); 
  delay(10);
  
}


void resetAll() {
  EEPROM.begin(4096);
  for (int i = 0; i < 4096; i++) {
    EEPROM.write(i, 0);
  }
  
  if (EEPROM.commit()) {
    Serial.println("Werkseinstellungen wiederhergestellt");
  } else {
    Serial.println("FEHLER beim leeren des Einstellungsspeichers!");
  }
  
  EEPROM.end();
  delay(10);
}

void generateHostname(){
    char newHostname[21] = DEFAULT_WIFI_HOSTNAME;
    char numbers[11] = "0123456789";
    
    newHostname[strlen(DEFAULT_WIFI_HOSTNAME)] = '-';

    for(int i = 0; i<6; i++){
      byte randomValue = random(0, 26);
      char letter = randomValue + 'a';
      int idx = strlen(newHostname);
      if(idx >= 20){
         break;
      }
      newHostname[idx] = letter;
    }

    setWifiHostname(newHostname);
    delay(10);
}

void setSwitchOn12V(float value){
  configuration.switchOn12V = value;
}

float getSwitchOn12V(){
  return configuration.switchOn12V;
}

void setSwitchOn24V(float value){
  configuration.switchOn24V = value;
}

float getSwitchOn24V(){
  return configuration.switchOn24V;
}

void setSwitchOff12V(float value){
  configuration.switchOff12V = value;
}

float getSwitchOff12V(){
  return configuration.switchOff12V;
}

void setSwitchOff24V(float value){
  configuration.switchOff24V = value;
}

float getSwitchOff24V(){
  return configuration.switchOff24V;
}

void setSsid(const char* value){
  strcpy(configuration.ssid, value);
}

char* getSsid(){
  return configuration.ssid;
}

void setWifiPassword(const char* value){
  strcpy(configuration.wifiPassword, value);
}

char* getWifiPassword(){
  return configuration.wifiPassword;
}

void setWifiHostname(const char* value){
  strcpy(configuration.wifiHostname, value);
}

char* getWifiHostname(){
  return configuration.wifiHostname;
}


void setVoltageFactor(float value){
  configuration.voltageFactor = value;
}

float getVoltageFactor(){
  return configuration.voltageFactor;
}

const char* getApName(){
  return DEFAULT_WIFI_AP_NAME;
}
