unsigned long timerToSleep = 0;
unsigned long nextExecution = 0;
int stopCounterTime = 0;
int executeDelay = 2000;

void checkButtonStatus() {
  if(readUpButtonState() == true) {
    timerToSleep = millis();    
    executeUp();
    nextExecution = millis() + executeDelay;
  } else if (readStopButtonState() == true) {
    timerToSleep = millis();
    stopCounterTime++;
    if (stopCounterTime > 20) {
      stopCounterTime = 0;
      executeMiddle();      
      nextExecution = millis() + 4000;
    }
  } else if (readDownButtonState() == true) {
    timerToSleep = millis();
    executeDown();
    nextExecution = millis() + executeDelay;
  } else if(stopCounterTime > 0){
    timerToSleep = millis();
    stopCounterTime = 0;
    executeStop();
    nextExecution = millis() + executeDelay;
  }
}

void loop() {
  checkLedStatus();
  updateAllLedStatus();

  if(millis() > nextExecution) {
    nextExecution = millis() + 100;
    checkButtonStatus();
  }
 
  if((millis() - timerToSleep) > 10000) {
    timerToSleep = millis();
    go_to_sleep();
  }
}
