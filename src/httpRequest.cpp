#include "config.h"
#include "HTTPClient.h"

// Private
String doRequest(String uri) {
  HTTPClient http;
  Serial.println("URI: " + uri);  
  String serverPath = serverName + uri;
  String payload = "";

  http.begin(serverPath.c_str());
  http.setUserAgent(boardUserAgent);

  int httpResponseCode = http.GET();

  if (httpResponseCode < 400) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  return payload;
}

// Private
void requestButton(String button) {
  doRequest("button/" + button + "/channel/" + String(defaultChannel));
}

void middleButtonPushed() {  
  doRequest("middle/channel/" + String(defaultChannel));
}

void upButtonPushed() {
  requestButton("up");
}

void stopButtonPushed() {
  requestButton("stop");
}

void downButtonPushed() {
  requestButton("down");
}

void sendEmailLowBattery() {
  doRequest("esp32/low-battery");
}

String getLastestVersion() {
  return doRequest("esp32/version");  
}