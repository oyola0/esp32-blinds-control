#ifndef Leds_h
#define Leds_h

class Leds {
  public:
    static void setup(int gpioPort, int channel) {
      ledcSetup(channel, 10000, 8);
      ledcAttachPin(gpioPort, channel);
      ledcWrite(channel, MAX);
    }

    void start(int channel) {
      for (int i=1; i<4; i++) {
        if(ledIsOnStatus[i] == FADEOUT) {
          ledIsOnStatus[i] = OFF;
        }        
      }

      if(ledIsOnStatus[channel] == OFF) {
        ledIsOnStatus[channel] = DECREASE;
      }      
    }

    void startAll() {
      for (int i=1; i<4; i++) {
        start(i);
      }
    }

    void stop(int channel) {
      ledIsOnStatus[channel] = OFF;
    }

    void stopAll() {
      for (int i=1; i<4; i++) {
        stop(i);
      }
    }

    void update() {
      if(millis() > timeToNextCheck) {
        timeToNextCheck = millis() + 1;
        
        for (int i=1; i<4; i++) {       
          if(ledIsOnStatus[i] == FADEOUT) {
            timeToNextCheck = millis() + 10;
            dutyCycles[i]--;            
          } else if(dutyCycles[i] < MAX && ledIsOnStatus[i] == OFF) {
            dutyCycles[i]++;            
          } else if(ledIsOnStatus[i] != OFF) {
            dutyCycles[i] = dutyCycles[i] + ledIsOnStatus[i];
            if(dutyCycles[i] <= 0) {
              ledIsOnStatus[i] = INCREASE;
            } else if(dutyCycles[i] >= MAX) {
              ledIsOnStatus[i] = DECREASE;
            }
          }

          ledcWrite(i, dutyCycles[i]);        
        }
      }
    }

    bool fadeout() {
      bool result = false;
      for (int i=1; i<4; i++) {
        ledIsOnStatus[i] = FADEOUT;
        if(dutyCycles[i] <= 0) {
          result = true;
        }
      }
      return result;
    }

  private:
    static int const MAX = 250;
    static int const OFF = 0;
    static int const INCREASE = 1;
    static int const DECREASE = -1;
    static int const FADEOUT = 10;

    long timeToNextCheck = 0;
    int ledIsOnStatus[4] = {OFF, OFF, OFF, OFF}; /* 0 = off, 1 = increase, -1 = decrease, 10 = fadeout */
    int dutyCycles[4] = {MAX, MAX, MAX, MAX};
};

#endif