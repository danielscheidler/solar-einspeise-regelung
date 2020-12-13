static const char CLASS_BTN_GREEN[]  = "btn-success";
static const char CLASS_BTN_YELLOW[] = "btn-warning";
static const char CLASS_BTN_RED[]    = "btn-danger";
static const char CLASS_BTN_GRAY[]   = "btn-secondary";

static const char LABEL_ON[]   = "Ein";
static const char LABEL_OFF[]  = "Aus";
static const char LABEL_AUTO[] = "Automatisch";

static const char STATUS_LABEL_FEED[] = "Einspeisung";
static const char STATUS_LABEL_LOAD[] = "Laden";

static const char HTML_HEAD[] = "<html lang='de'><head><meta http-equiv='refresh' content='60' name='viewport' content='width=device-width, initial-scale=1'/>" \
                                "<style>" \
                                "  * {color: black; font-size: xx-large;}" \
                                "  body {background-color: white;}" \
                                "  h1 {font-size:150%}" \
                                "  input.btn-success {background-color: green; color: black;}" \
                                "  input.btn-warning {background-color: yellow; color: black;}" \
                                "  input.btn-danger {background-color: red; color: black;}" \
                                "  input.btn-secondary {background-color: gray; color: black;}" \
                                "  table.list {border: 1px solid gray;}" \
                                "  table.list > tr > td {border: 1px solid gray; padding: 7px 20px 7px 20px;}" \
                                "  hr {color: red;}" \
                                "</style>" \
                                "<title>UTUBERLARS - Einspeise Regelung</title>" \
                                "</head><body>" \
                                "<div class='container-fluid'>" \
                                "<div class='row'>" \
                                "<div class='col-md-12'>" \
                                "<a href='https://www.youtube.com/channel/UCWzgOrFuh82znXetsW3pmAA' target='utlyt'>" \
                                  "<img src='data:image/png;base64,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'>" \
                                "</a>" \
                                "<h1>UTUBERLARS - Einspeise Regelung</h1>" \
                                "<a href='https://guerilla-stromer.de' target='utl'><h3>https://guerilla-stromer.de</h3></a>";
                          
static const char HTML_FOOT[] = "</div></div></div><br/><br/><br/>" \
                                "<table style='width:100%; background-color:#dedede; position:fixed; left:0px; bottom:0px; padding: 5px 5px;'><tr><td>Supported by: <a href='https://smarthomeyourself.de' target='shys'>https://smarthomeyourself.de</a> " \
                                "| <a href='https://www.youtube.com/SmartHomeYourselfDe_DIY' target='shysyt'>https://www.youtube.com/SmartHomeYourselfDe_DIY</a></td>" \
                                "</tr></table>" \
                                "</body></html>";

static const char HTML_STATUS_TBL_BATTERY_TYPE[] = "<br/><br/>" \
                                                   "<table class='list'>" \
                                                   "<thead><tr><th style='width: 150px;'>Name</th><th style='width: 150px;'>Wert</th><th style='width: 150px;'>Einheit</th></tr></thead>" \
                                                   "<tbody>" \
                                                   "<tr><td class='col-xs-3'>Batterie Art</td><td class='col-xs-3'>";

static const char HTML_STATUS_TBL_VOLTAGE[] = "</td><td class='col-xs-3'>V</td></tr>" \
                                              "<tr class='active'><td>Aktuelle Spannung (Volt)</td><td>";

static const char HTML_STATUS_TBL_SWITCH_VALUE[] = "</td><td>V</td></tr>" \
                                                   "<tr><td>Einspeisen ab</td><td>";

static const char HTML_STATUS_TBL_SWITCH_OFF_VALUE[] = "</td><td>V</td></tr>" \
                                                       "<tr class='active'><td>Laden unter</td><td>";

static const char HTML_STATUS_TBL_MODUS[] = "</td><td>V</td></tr>" \
                                             "<tr><td>Modus</td><td>";

static const char HTML_STATUS_TBL_STATUS[] = "</td><td></td></tr>" \
                                             "<tr><td>Relais-Status</td><td>";

static const char HTML_STATUS_TBL_END[] = "</td><td></td></tr>" \
                                          "</tbody>" \
                                          "</table>";

static const char HTML_MANUAL_SWITCH_TOP[] = "<br/><h3>Manuelle Schaltung</h3>" \
                                             "<h4 class ='text-left'>Einspeisung</h4>";

static const char HTML_MANUAL_SWITCH_END[] = "<br/><br/><br/><br/>" \
                                             "<a href='/admin'>Einstellungen</a>" \
;  


static const char HTML_BUTTON_BEGIN[] = "<td><form action='/' method='POST'><input type='hidden' name='RelaisMode' value='";

static const char HTML_BUTTON_LABEL[] = "'><input type='submit' value='";

static const char HTML_BUTTON_CLASS[] = "' class='btn ";

static const char HTML_BUTTON_STYLE[] = " btn-lg' style='width:10em;' />";

static const char HTML_BUTTON_END[] = "</form></td>";


static const char HTML_ADMIN_HOSTNAME[] = "<hr/><form action='/' method='POST'>" \
                                          "<table>" \
                                          "<tr>" \
                                            "<td colspan='2' ><h2 style='margin-block-start:0;'>Ger&auml;te Einstellung</h2></td>" \
                                          "</tr><tr>" \
                                            "<td>Hostname:</td> <td><input type='text' class='form-control' name='wifi_hostname' maxlength='20' value='";

static const char HTML_ADMIN_SSID[] = "'></td></tr><tr><td colspan='2'><hr/></td></tr><tr>" \
                                         "<td colspan='2' ><h2 style='margin-block-start:0;'>WLAN Einstellungen</h2></td>" \
                                       "</tr><tr>" \
                                         "<td>SSID:</td> <td><input type='text' class='form-control' name='ssid_name' maxlength='32' value='";
    
static const char HTML_ADMIN_WIFI_PW[] = "'></td></tr><tr>" \
                                           "<td>Passwort:</td> <td><input type='password' class='form-control' name='wifi_password' maxlength='63' value='";

static const char HTML_ADMIN_12V_OFF[] = "'></td></tr><tr><td colspan='2'><hr/></td></tr><tr>" \
                                           "<td><h2 style='margin-block-start:0;'>Relais Einstellungen</h2></td>" \
                                         "</tr><tr>" \
                                           "<td colspan='2'><h3>bei 12V</h3></td>" \
                                         "</tr><tr>" \
                                           "<td>Einspeisung abschalten unter:</td> <td><input class='form-control' name='switchOff12' maxlength='10' value='";

static const char HTML_ADMIN_12V_ON[] = "'/></td></tr><tr>" \
                                           "<td>Einspeisung einschalten ab:</td> <td><input class='form-control' name='switchOn12' maxlength='10' value='";
                                     
static const char HTML_ADMIN_END[] =   "'/></td></tr><tr><td colspan='2'><hr/></td></tr><tr><td>" \
                                         "<input type='submit' class='btn-success btn btn-lg' name='saveSettings' value='Speichern'> " \
                                       "</td><td style='text-align:right'>" \
                                         "<input type='button' onclick=\"window.location.replace('/')\"  class='btn-danger btn btn-lg' value='Abbrechen'></form>"\
                                       "</td></tr><tr><td colspan='2'><br/><br/><br/><br/></td></tr>" \
                                       "<tr><td colspan='2'><a href='/calibrate'>Spannungssensor kalibrieren</a></td></tr>" \
                                       "</table>";

static const char HTML_CALIBRATE[] = "<form action='/' method='POST'><table>" \
                                     "<tr><td>Messen Sie die Spannung am Spannungseingang der Platine und tragen Sie den Wert im Textfeld ein.<br/>Best&auml;tigen Sie den Wert anschließend mit einem Klick auf *Kalibrieren*<br/><br/>  </td></tr>" \
                                     "<tr><td><input type='text' name='currentVoltageInput'/><input type='submit' name='calibrateSubmit' value='Kalibrieren'/></td></tr>" \
                                     "</table></form>";


const char * getButtonClassName(int relaisMode){
  switch(relaisMode){

     case RELAIS_MODE_ON:
       return currentRelaisMode==RELAIS_MODE_ON ? CLASS_BTN_GREEN : CLASS_BTN_GRAY;
       break;

     case RELAIS_MODE_OFF:
       return currentRelaisMode==RELAIS_MODE_OFF ? CLASS_BTN_RED : CLASS_BTN_GRAY;
       break;

     case RELAIS_MODE_AUTO:
       return currentRelaisMode==RELAIS_MODE_AUTO ? CLASS_BTN_YELLOW : CLASS_BTN_GRAY;
       break;
       
     default:
       return CLASS_BTN_GRAY;

       break;
  }
}

const char * getCurrentRelaisModeLabel(){
  switch(currentRelaisMode){
     case RELAIS_MODE_ON:
       return LABEL_ON;
       break;

     case RELAIS_MODE_OFF:
       return LABEL_OFF;
       break;

     case RELAIS_MODE_AUTO:
     default:
       return LABEL_AUTO;

       break;
  }
}

String getSwitchHtml(const char* label, int relaisMode){

  String htmlButton = HTML_BUTTON_BEGIN;
  htmlButton +=       relaisMode;
  htmlButton +=       HTML_BUTTON_LABEL;
  htmlButton +=       label;
  htmlButton +=       HTML_BUTTON_CLASS;
  htmlButton +=       getButtonClassName(relaisMode);
  htmlButton +=       HTML_BUTTON_STYLE;
  htmlButton +=       HTML_BUTTON_END;

  return htmlButton;
}

String getCalibrateHtml(){
  String page = HTML_HEAD;
  page += HTML_CALIBRATE;
  page += HTML_FOOT;

  return page;
}

String getAdminUi(){
  String page = HTML_HEAD;
  page += HTML_ADMIN_HOSTNAME;
  page +=   getWifiHostname();
  page += HTML_ADMIN_SSID;  
  page +=   getSsid();
  page += HTML_ADMIN_WIFI_PW;
  page +=   getWifiPassword();

  page += HTML_ADMIN_12V_OFF;
  page +=   getSwitchOff12V();
  page += HTML_ADMIN_12V_ON;
  page +=   getSwitchOn12V();
   
  page += HTML_ADMIN_END;
  page += HTML_FOOT;
  
  return page;
}

String getFrontend(){
  String page = HTML_HEAD;

  // Tabelle: Anzeige aktueller Daten
  page += HTML_STATUS_TBL_BATTERY_TYPE;
  page +=   batteryType;
  
  page += HTML_STATUS_TBL_VOLTAGE;
  page +=   currentVoltage;
  
  page += HTML_STATUS_TBL_SWITCH_VALUE;
  page +=   getSwitchOnValue();

  page += HTML_STATUS_TBL_SWITCH_OFF_VALUE;
  page +=   getSwitchOffValue();
  delay(1);
  page += HTML_STATUS_TBL_MODUS;
  page +=   getCurrentRelaisModeLabel();

  page += HTML_STATUS_TBL_STATUS;
  page +=   currentRelaisStatus ? STATUS_LABEL_FEED : STATUS_LABEL_LOAD;
  
  page += HTML_STATUS_TBL_END;

  // Manuelle Steuerung
  page += HTML_MANUAL_SWITCH_TOP;
                    
  page += getSwitchHtml(LABEL_ON, RELAIS_MODE_ON); 
  page += getSwitchHtml(LABEL_OFF, RELAIS_MODE_OFF); 
  page += getSwitchHtml(LABEL_AUTO, RELAIS_MODE_AUTO);  
  
  page += HTML_MANUAL_SWITCH_END;
  
  page += HTML_FOOT;
  
  return page;
}
