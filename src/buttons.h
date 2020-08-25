#include "Leds.h"

class Buttons {
  public:
    bool upButtonIsPushed() {
      return genericReadButtonState(gpioUpButton, upChannel);
    }

    bool stopButtonIsPushed() {
      return genericReadButtonState(gpioStopButton, stopChannel);  
    }

    bool downButtonIsPushed() {
      return genericReadButtonState(gpioDownButton, downChannel);  
    }

    void updateAllLedStatus() {
      leds.update();

      if(millis() > nextExecution) {
        nextExecution = millis() + 100;
        genericReadButtonState(gpioUpButton, upChannel);
        genericReadButtonState(gpioStopButton, stopChannel);
        genericReadButtonState(gpioDownButton, downChannel);
      }   
    }

    bool fadeoutIsFinished() {
      return leds.fadeout();
    }    

  private:
    long nextExecution = 0;
    Leds leds;

    bool genericReadButtonState(int gpioBtn, int gpioChannel) {
      int buttonState = digitalRead(gpioBtn);
      if(buttonState == HIGH) {
        leds.start(gpioChannel); 
        return true;
      } else {
        leds.stop(gpioChannel); 
        return false;
      }  
    }
};
