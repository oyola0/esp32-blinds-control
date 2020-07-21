
#define WiFiSSID            "WIFI SSID"
#define WiFiPassword        "WIFI_PASSWORD"

#define serverName          "http://SERVER_IP:8080/api/"
#define boardUserAgent      "ESP32 board (kitchen blind)"

#define defaultChannel      3

#define gpioUpButton        15
#define gpioUpLed           18
#define upChannel           1

#define gpioStopButton      2
#define gpioStopLed         19
#define stopChannel         2

#define gpioDownButton      4
#define gpioDownLed         21
#define downChannel         3

#define BUTTON_PIN_BITMASK  0x8014  /* GPIO15, GPIO2, GPIO4 = 2^15 + 2^2 + 2^4 */
