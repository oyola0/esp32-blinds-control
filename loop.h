#include "Buttons.h"

class Loop {
  public:
    bool loop() {      
      buttons.updateAllLedStatus();
      checkIfAnyButtonIsPushed();      

      if((millis() - timerToSleep) > 10000 && buttons.fadeoutIsFinished()) {
        go_to_sleep();     
      }
    }

  private:
    long timerToSleep = 0;
    long nextExecution = 0;
    int stopCounterTime = 0;
    int executeDelay = 2000;
    Buttons buttons;

    void checkIfAnyButtonIsPushed() {
      if(millis() > nextExecution) {
        nextExecution = millis() + 100;

        if(buttons.readUpButtonState() == true) {
          timerToSleep = millis();   
          upButtonPushed();
          nextExecution = millis() + executeDelay;
        } else if(buttons.readStopButtonState() == true) {
          timerToSleep = millis();
          stopCounterTime++;
          if (stopCounterTime > 20) {
            stopCounterTime = 0;
            middleButtonPushed();      
            nextExecution = millis() + 4000;
          }
        } else if(buttons.readDownButtonState() == true) {
          timerToSleep = millis();
          downButtonPushed();
          nextExecution = millis() + executeDelay;
        } else if(stopCounterTime > 0){
          timerToSleep = millis();
          stopCounterTime = 0;
          stopButtonPushed();
          nextExecution = millis() + executeDelay;
        }
      }      
    }
};

Loop loopExecutor;

void loop() {
  loopExecutor.loop();
}