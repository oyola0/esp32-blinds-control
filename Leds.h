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
      if(ledIsOnStatus[channel] != true) {
        ledcWrite(channel, MAX);
        ledIsOnStatus[channel] = true;
        directions[channel] = -1;
      }  
    }

    void stop(int channel) {
      ledIsOnStatus[channel] = false;
    }

    void update() {
      if(millis() > timeToNextCheck) {
        timeToNextCheck = millis() + 1;
        
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

  private:
    static int const MAX = 250;
    long timeToNextCheck = 0;
    bool ledIsOnStatus[4] = {false, false, false, false};
    int directions[4] = {-1, -1, -1 ,-1};
    int dutyCycles[4] = {MAX, MAX, MAX, MAX};
};

#endif