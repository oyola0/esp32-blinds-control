#include "httpRequest.h"

void executeUp(){  
  upButton(defaultChannel);  
}

void executeStop(){  
  stopButton(defaultChannel);  
}

void executeDown(){  
  downButton(defaultChannel);
}

void executeMiddle(){  
  requestMiddle(defaultChannel);
}

void initExecuteButton() {
  int gpioBtn = get_GPIO_wake_up();
  if(gpioUpButton == gpioBtn) {
    executeUp();
  } else if (gpioStopButton == gpioBtn) {
    executeStop();
  } else if (gpioDownButton == gpioBtn) {
    executeDown();
  }
}
