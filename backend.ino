static const int BATTERY_TYPE_12V = 12;
static const int PIN_STEPS = 1024;

static const int RELAIS_MODE_ON   = 0;
static const int RELAIS_MODE_OFF  = 1;
static const int RELAIS_MODE_AUTO = 2;

static const char PARAMETER_RELAIS_MODE[] = "RelaisMode";

static const float MAX_VOLTAGE = 30.0f;
static const float GPIO_REF_VOLTAGE = 3.3f;
static const float VOLTAGE_SENSOR_RESISTOR_VIN = 22000.0f;
static const float VOLTAGE_SENSOR_RESISTOR_GND = 2200.0f;

float currentVoltage = 0.0f;
int batteryType = BATTERY_TYPE_12V;
int currentRelaisMode = RELAIS_MODE_AUTO;
boolean currentRelaisStatus = false;

int lastVoltageRefresh = millis();


void checkStates(){
  refreshCurrentVoltage();
  
  if(currentRelaisMode == RELAIS_MODE_AUTO){
    refreshRelaisStatus();
  }
  
  refreshStatusLed();
}

void refreshStatusLed(){
  if(currentRelaisStatus){
    int chk = (millis()/500);
    digitalWrite(LED_PIN, chk%2==0?HIGH:LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }
}

void refreshCurrentVoltage(){
  if(lastVoltageRefresh + voltageRefreshIntervall < millis()){
    float readVal = analogRead(VOLTAGE_SENSOR_PIN);
    float tmpVal = (readVal * GPIO_REF_VOLTAGE) / PIN_STEPS;
    float factor = (VOLTAGE_SENSOR_RESISTOR_GND / (VOLTAGE_SENSOR_RESISTOR_VIN + VOLTAGE_SENSOR_RESISTOR_GND));
    currentVoltage = tmpVal / factor * getVoltageFactor();
    
    Serial.print("Current Val: ");
    Serial.println(currentVoltage);

    lastVoltageRefresh = millis();
  }
  delay(1);
}

float getSwitchOnValue(){
  return batteryType == BATTERY_TYPE_12V ? getSwitchOn12V() : getSwitchOn24V();
}

float getSwitchOffValue(){
  return batteryType == BATTERY_TYPE_12V ? getSwitchOff12V() : getSwitchOff24V();
}

void refreshRelaisStatus(){
  if(currentRelaisStatus){
    if(currentVoltage < getSwitchOffValue()){
      switchRelais(false);
    }
  } else {
    if(currentVoltage > getSwitchOnValue()){
      switchRelais(true);
    }
  }
  delay(1);
}

void switchRelais(boolean state){
  currentRelaisStatus = state;
  digitalWrite(RELAIS_PIN, state?HIGH:LOW);
  delay(1);
}

void handleAdmin(){ 
  server.send ( 200, "text/html", getAdminUi() );
  delay(1);
}

void handleCalibrate(){
  server.send ( 200, "text/html", getCalibrateHtml() );
  delay(1);
}


void handleAdminUrlParams(){
  if ( server.hasArg("wifi_hostname") && server.arg("wifi_hostname") != NULL) {
    setWifiHostname(server.arg("wifi_hostname").c_str());
  }
  
  if ( server.hasArg("ssid_name") && server.arg("ssid_name") != NULL) {
    setSsid(server.arg("ssid_name").c_str());
  }
  
  if ( server.hasArg("wifi_password") && server.arg("wifi_password") != NULL) {
    setWifiPassword(server.arg("wifi_password").c_str());
  }
  
  if ( server.hasArg("switchOff12") && server.arg("switchOff12") != NULL) {
    setSwitchOff12V(getFloat(server.arg("switchOff12")));
  }
  
  if ( server.hasArg("switchOn12") && server.arg("switchOn12") != NULL) {
    setSwitchOn12V(getFloat(server.arg("switchOn12")));
  }
  
  if ( server.hasArg("switchOff24") && server.arg("switchOff24") != NULL) {
    setSwitchOff24V(getFloat(server.arg("switchOff24")));
  }
  
  if ( server.hasArg("switchOn24") && server.arg("switchOn24") != NULL) {
    setSwitchOn24V(getFloat(server.arg("switchOn24")));
  }

  saveConfig();
  
  delay(1);
}


void handleCalibrateUrlParams(){
  if ( server.hasArg("currentVoltageInput") && server.arg("currentVoltageInput") != NULL) {
    float calibrateVoltage = getFloat(server.arg("currentVoltageInput"));

    float readVal = analogRead(VOLTAGE_SENSOR_PIN);
    float tmpVal = (readVal * GPIO_REF_VOLTAGE) / PIN_STEPS;
    float resistorFactor = (VOLTAGE_SENSOR_RESISTOR_GND / (VOLTAGE_SENSOR_RESISTOR_VIN + VOLTAGE_SENSOR_RESISTOR_GND));
    float tmpVoltage = tmpVal / resistorFactor;
    
    float newFactor = calibrateVoltage / tmpVoltage;
    Serial.print("new factor: ");
    Serial.println(newFactor);

    setVoltageFactor(newFactor);
  }
  
  saveConfig();
  
  delay(1);
}


float getFloat(String val){
  val.replace(",",".");
  return val.toFloat();
}

void handleRoot(){ 
  handleUrlParams();
  server.send ( 200, "text/html", getFrontend() );
}

void handleUrlParams(){
  if ( server.hasArg(PARAMETER_RELAIS_MODE) && server.arg(PARAMETER_RELAIS_MODE) != NULL) {
    int tmp = server.arg(PARAMETER_RELAIS_MODE).toInt();
    
    switch (tmp){
      case RELAIS_MODE_ON:
        currentRelaisMode = tmp;
        currentRelaisStatus = true;
        digitalWrite(RELAIS_PIN, HIGH);

        break;
        
      case RELAIS_MODE_OFF:
        currentRelaisMode = tmp;
        switchRelais(false);
        
        break;
        
      case RELAIS_MODE_AUTO:
        currentRelaisMode = tmp;
        checkStates();
        
        break;
        
      default:
        currentRelaisMode = RELAIS_MODE_AUTO;
        
        break;
    }
    delay(1);
  }

  if( server.hasArg("saveSettings") && server.arg("saveSettings") == "Speichern"){
      handleAdminUrlParams();
  }

  
  if( server.hasArg("calibrateSubmit") && server.arg("calibrateSubmit") == "Kalibrieren"){
      handleCalibrateUrlParams();
  }

}
