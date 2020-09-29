# esp32-blinds-control

This project is useful for controlling the blind. Related to another [jarolift domotic project](https://github.com/oyola0/jarolift-domotic)

#### Required

* 1 ESP32
* 1 [ESP32 adaptor board](https://www.aliexpress.com/item/32811323132.html?spm=a2g0s.9042311.0.0.42824c4dZQ09Lq)
* 1 MCP1700
* 1 Capacitor 100µF
* 1 Capacitor 10nF
* 3 Resistance 12 ohms
* 2 Resistance 47k
* 2 [White LED Light Momentary 3V](https://es.aliexpress.com/item/32812948786.html?spm=a2g0s.9042311.0.0.37cd63c0dXF9Tt)
* 1 [Red LED Light Momentary 3V](https://www.aliexpress.com/item/32812948786.html?spm=a2g0s.9042311.0.0.37cd63c0dXF9Tt)
* 1 [3 x AA Power Battery Case Box](https://www.aliexpress.com/item/4000931485961.html?spm=a2g0o.productlist.0.0.7bdd1bf9TmRz4M&s=p&ad_pvid=202009251045517112643326926650001396654_1&algo_pvid=7fb23bb9-e7e4-4cd8-8b5b-72cb9f428f72&algo_expid=7fb23bb9-e7e4-4cd8-8b5b-72cb9f428f72-0&btsid=0b0a0ae216010559513543439e25ed&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)

## Variables defined in the config.h file
* __WiFiSSID__ Wifi SSID
* __WiFiPassword__ Wifi password
* __serverName__ Jarolift exposed API e.g. http://{SERVICE_IP}:8080/api/
* __boardUserAgent__ User Agent Name
* __binVersion__ Binary version
* __gpioBatteryLevel__ GPIO to read the battery level (default: 34)
* __defaultChannel__ The channel that you want to manage(default: 2)
* __gpioUpButton__ Up button GPIO (default: 15)
* __gpioUpLed__ GPIO for Up button LED (default: 18)
* __upChannel__ Up channel LED (default: 1)
* __gpioStopButton__ Stop button GPIO (default: 2)
* __gpioStopLed__ GPIO for Stop button LED (default: 19)
* __stopChannel__ Stop channel LED (default: 2)
* __gpioDownButton__ Down button GPIO (default: 4)
* __gpioDownLed__ GPIO for Down button LED (default: 21)
* __downChannel__ Down channel LED (default: 3)
* __BUTTON_PIN_BITMASK__ GPIOs Mask for several wake up (default: 0x8014)

## How does it work? 
From deep sleep mode, wakes up when any button is pressed

1. Connecting WIFI (blinking all the LEDs until the wifi is connected)
2. Checking battery level
3. Execute the button pressed command (up, stop, down)
4. It will wait for another button to be pressed for 20 seconds
5. Checking OTA updates (blinking stop button during the process)
6. Return to sleep mode (fadeout of all buttons)

## Circuit diagram

<p align="center">
   <img alt="circuit diagram" src="./docs/circuit_diagram.png" />
</p>