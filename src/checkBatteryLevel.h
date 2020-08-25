
void checkBatteryLevel() {
  float pinValue = analogRead(gpioBatteryLevel);
  double volts = pinValue * 1.73 / 1000;

  Serial.print("Battery Voltage = "); 
  Serial.print(volts, 2); 
  Serial.println(" V");

  if(volts < 3.4) {
    sendEmailLowBattery();
  }
}
