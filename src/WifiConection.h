#include "WiFi.h"
#include "Leds.h"

bool connectToWiFiSuccess() {  
  long errorTimer = millis() + 30000;
  bool connectionSuccess = true;
  Leds leds;

  Serial.println();
  Serial.print("WIFI: Connecting");
  WiFi.begin(WiFiSSID, WiFiPassword);
  
  leds.startAll();
  while (connectionSuccess && WiFi.status() != WL_CONNECTED) {
    delay(1);
    if(millis() > errorTimer) {
      connectionSuccess = false;
    }
    leds.update();
  }
  leds.stopAll();

  Serial.println();
  if(connectionSuccess) {    
    Serial.println("WIFI: Connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WIFI: ERROR");
  }

  return connectionSuccess;
}
