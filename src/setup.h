#include "Leds.h"
#include "WifiConection.h"
#include "checkBatteryLevel.h"

void setup() {
  Serial.begin(115200);

  pinMode(gpioUpButton, INPUT);
  pinMode(gpioStopButton, INPUT);
  pinMode(gpioDownButton, INPUT);
    
  Leds::setup(gpioUpLed, upChannel);
  Leds::setup(gpioStopLed, stopChannel);
  Leds::setup(gpioDownLed, downChannel);
      
  if(connectToWiFiSuccess()) {
    print_GPIO_wake_up();
    checkBatteryLevel();

    int gpioBtn = get_GPIO_wake_up();
    if(gpioUpButton == gpioBtn) {
      upButtonPushed();
    } else if (gpioStopButton == gpioBtn) {
      stopButtonPushed();
    } else if (gpioDownButton == gpioBtn) {
      downButtonPushed();
    } 
  } else {
    go_to_sleep();
  }
}
