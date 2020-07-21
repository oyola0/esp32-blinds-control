#include "config.h"
#include "HTTPClient.h"

// Private
void doRequest(String uri) {
  HTTPClient http;
  Serial.println("URI: " + uri);  
  String serverPath = serverName + uri;

  http.begin(serverPath.c_str());
  http.setUserAgent(boardUserAgent);

  int httpResponseCode = http.GET();

  if (httpResponseCode < 400) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

// Private
void requestButton(String button, int channel) {
  doRequest("button/" + button + "/channel/" + String(channel));
}

void requestMiddle(int channel) {  
  doRequest("middle/channel/" + String(channel));
}

void upButton(int channel) {
  requestButton("up", channel);
}

void stopButton(int channel) {
  requestButton("stop", channel);
}

void downButton(int channel) {
  requestButton("down", channel);
}

void requestLowBattery() {
  doRequest("esp32/low-battery");
}
