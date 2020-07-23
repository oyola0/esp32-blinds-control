#include "Leds.h"

class Buttons {
  public:
    bool readUpButtonState() {
      return genericReadButtonState(gpioUpButton, upChannel);
    }

    bool readStopButtonState() {
      return genericReadButtonState(gpioStopButton, stopChannel);  
    }

    bool readDownButtonState() {
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
