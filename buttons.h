long nextButtons = 0;

bool genericReadButtonState(int gpioBtn, int gpioChannel) {
  int buttonState = digitalRead(gpioBtn);
  if(buttonState == HIGH) {
    ledStart(gpioChannel); 
    return true;
  } else {
    ledStop(gpioChannel); 
    return false;
  }  
}

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
  if(millis() > nextButtons) {
    nextButtons = millis() + 100;
    genericReadButtonState(gpioUpButton, upChannel);
    genericReadButtonState(gpioStopButton, stopChannel);
    genericReadButtonState(gpioDownButton, downChannel);
  }   
}
