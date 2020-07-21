int MAX = 100;
bool ledIsOnStatus[] = {false, false, false, false};
int directions[] = {-1, -1, -1 ,-1};
int dutyCycles[] = {MAX, MAX, MAX, MAX};
long timeToNextCheck = 0;

void ledSetup(int gpioPort, int channel) {
  ledcSetup(channel, 10000, 8);
  ledcAttachPin(gpioPort, channel);
  ledcWrite(channel, MAX);
}

void ledStart(int channel) {
  if(ledIsOnStatus[channel] != true) {
    ledcWrite(channel, MAX);
    ledIsOnStatus[channel] = true;
    directions[channel] = -1;
  }  
}

void ledStop(int channel) {
  ledIsOnStatus[channel] = false;
}

void checkLedStatus() {
  if(millis() > timeToNextCheck) {
    timeToNextCheck = millis() + 5;
    
    for (int i=1; i<4; i++) {
      if(dutyCycles[i] < MAX && ledIsOnStatus[i] == false) {
        dutyCycles[i]++;
        ledcWrite(i, dutyCycles[i]);
      } else if(ledIsOnStatus[i] == true) {
        dutyCycles[i] = dutyCycles[i] + directions[i];
        if(dutyCycles[i] <= 0) {
          directions[i] = +1;
        } else if(dutyCycles[i] >= MAX) {
          directions[i] = -1;
        }
        ledcWrite(i, dutyCycles[i]);
      }
    }
  }  
}
