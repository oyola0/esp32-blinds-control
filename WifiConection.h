#include "WiFi.h"

void ConnectToWiFi() {  
  Serial.println();
  
  Serial.print("WIFI: Connecting");

  WiFi.begin(WiFiSSID, WiFiPassword);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }

  Serial.println();
  Serial.println("WIFI: Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
