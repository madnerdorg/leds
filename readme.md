[Version française / French version](https://github.com/madnerdorg/utest/blob/master/README.fr.MD)

![Photo leds](https://github.com/madnerdorg/leds/raw/master/doc/universalLed_photo.jpg)   
leds is an USB device based on an Arduino nano (clone) to easily control 5 leds.

# Components
* Arduino nano CH340G: 2€
* 30 leds WS2812B : 4.50€ ( 5 leds :0.75€)
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 9.5€ (2.75€)

# Wiring
Wiring / How to make it: https://www.youtube.com/watch?v=hgvi46x4oaE

Do not used more than 5 leds without a dedicated power supply or this can damage the leds   
Each led can draw up to **60ma** at full brightness   
An Arduino can provided up to **500ma** (on 5v/Gnd pin)   
```5 leds = 5x60ma = 300ma ```  
Source:
https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections

* D6 --> RESISTOR (470Ohm) DI
* +5V --> 5V
* GND --> GND

![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/universalLed_wiring.png)

# 3D printing
Models by Olivier Sarrailh : https://github.com/madnerdorg/leds/tree/master/3D    
You will need to fill a hole for the led strip (see wiring instructions)

# Commands available
You can test the device in Arduino Serial Monitor   
Baudrate : 115200 / No Line Ending   

* leds --------> Check if device is correct (turn off all led)
* /info -------> Give name of device
* X:Y -------> (Where X is the led and Y the color)
* 1:3 -------> (led 1 Green)

# Color
* 0 : OFF
* 1 : White/ON
* 2 : Red
* 3 : Green
* 4 : Blue
* 5 : Yellow
* 6 : Orange
* 7 : Purple

# Licences

Software by Rémi Sarrailh (madnerd.org)   
Licence: MIT
