
#include "config.h"
#include "sleepFunctions.h"
#include "WifiConection.h"
#include "LedFadding.h"
#include "execute.h"
#include "buttons.h"
#include "loop.h"

void setup() {
  Serial.begin(9600);
  
  pinMode(gpioUpButton, INPUT);
  pinMode(gpioStopButton, INPUT);
  pinMode(gpioDownButton, INPUT);
  
  ledSetup(gpioUpLed, upChannel);
  ledSetup(gpioStopLed, stopChannel);
  ledSetup(gpioDownLed, downChannel);
  
  ConnectToWiFi(); 
  print_GPIO_wake_up();
  initExecuteButton();   
}
