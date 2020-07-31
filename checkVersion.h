#include "UpdateESP.h"

void checkVersion() {
  String apiVersion = getLastestVersion();

  if(apiVersion.length() > 0 && apiVersion != binVersion) {
    Serial.println("Updating...");

    String serverPath = serverName + String("esp32/update");
    Serial.println("URI: " + serverPath);  
    WiFiClient client;
    ledcDetachPin(gpioStopLed);
    httpUpdate.setLedPin(gpioStopLed);

    t_httpUpdate_return ret = httpUpdate.update(client, serverPath);

    switch (ret) {
      case HTTP_UPDATE_FAILED:
        Serial.printf("HTTP_UPDATE_FAILED Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
        break;

      case HTTP_UPDATE_NO_UPDATES:
        Serial.println("HTTP_UPDATE_NO_UPDATES");
        break;

      case HTTP_UPDATE_OK:
        Serial.println("HTTP_UPDATE_OK");
        break;
    }

  }  
}
