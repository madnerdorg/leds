[Version française / French version](https://github.com/madnerdorg/leds/blob/master/readme.fr.md)

![Photo leds](https://github.com/madnerdorg/leds/raw/master/doc/leds.jpg)   
leds is an USB device based on an Arduino nano (clone) to easily control 5 leds.

# Usage
* Copy **libraries/leds** into your arduino sketchbook
* Upload **leds/leds.ino**
* Go to [TODO]

![colors](https://github.com/madnerdorg/leds/raw/master/doc/leds_colors.png)

# Components
* Arduino nano CH340G: 2€
* 30 leds WS2812B : 4.50€ ( 5 leds :0.75€)
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 9.5€ (2.75€)

# Wiring
Do not used more than 5 leds without a dedicated power supply or this can damage the leds   
Each led can draw up to **60ma** at full brightness   
An Arduino can provided up to **500ma** (on 5v/Gnd pin)   
```5 leds = 5x60ma = 300ma ```  
Source:
https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections

* D6 --> RESISTOR (470Ohm) DI
* +5V --> 5V
* GND --> GND

![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds_wiring.jpg)

# 3D printing
Models by Olivier Sarrailh : https://github.com/madnerdorg/leds/tree/master/3D    

# Commands available
* /info -------> Give name of device (name:port) (leds:42001)
* A;B;C;D;E -------> (Where A is led1 color etc...)
* 0 ---> Turn off all leds

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

## leds.ino
* Author: Rémi Sarrailh (madnerd.org)   
* Licence: MIT

## FastLed
* Main author: Daniel Garcia (fastled)
* Licence: MIT
* Link : https://github.com/FastLED/FastLED
