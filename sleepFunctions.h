
void go_to_sleep() {
  esp_sleep_enable_ext1_wakeup(BUTTON_PIN_BITMASK, ESP_EXT1_WAKEUP_ANY_HIGH);
  Serial.println("Going to sleep now");
  // delay(1000);
  esp_deep_sleep_start();
}

int get_GPIO_wake_up() {
  int GPIO_reason = esp_sleep_get_ext1_wakeup_status();
  return (int)((log(GPIO_reason))/log(2));
}

void print_GPIO_wake_up(){
  Serial.print("GPIO that triggered the wake up: GPIO ");
  Serial.println(get_GPIO_wake_up());  
}
