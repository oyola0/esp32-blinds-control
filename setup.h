#include "Leds.h"
#include "WifiConection.h"

void setup() {
  Serial.begin(9600);

  pinMode(gpioUpButton, INPUT);
  pinMode(gpioStopButton, INPUT);
  pinMode(gpioDownButton, INPUT);
    
  Leds::setup(gpioUpLed, upChannel);
  Leds::setup(gpioStopLed, stopChannel);
  Leds::setup(gpioDownLed, downChannel);
  
  ConnectToWiFi(); 
  print_GPIO_wake_up();

  int gpioBtn = get_GPIO_wake_up();
  if(gpioUpButton == gpioBtn) {
    upButtonPushed();
  } else if (gpioStopButton == gpioBtn) {
    stopButtonPushed();
  } else if (gpioDownButton == gpioBtn) {
    downButtonPushed();
  } 
}
