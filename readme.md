[Version française / French version](https://github.com/madnerdorg/leds/blob/master/readme.fr.md)


![Photo LEDs](https://github.com/madnerdorg/leds/raw/master/doc/leds2.gif)   
**leds** is an USB device based on an Arduino nano (clone) to control 1 or more LEDs.   
You can animate each leds independantly, and change the color using hsv colors.

* [Download Object](https://github.com/madnerdorg/leds/archive/master.zip)
* [Download LibreConnect](https://github.com/madnerdorg/libreconnect/releases)

# Applications
Required [LibreConnect](https://github.com/madnerdorg/libreconnect/releases)

* [apps/html](https://github.com/madnerdorg/leds/tree/master/apps)  
Setup your leds using a webpage, once you like how your leds shines, save it and then it will remembers its state some
you can use it wherever you want!   

* [apps/tasker](https://github.com/madnerdorg/leds/tree/master/apps)    
Be notified when someone calls you, using tasker and some easy to use javascript scripts.
You can trigger leds for any events that happens on your phone!

* apps/thunderbird [TODO]    
Be notified when someone sends you an email, using **filters** and **mail alerts** plugin.

# Build

## Arduino
First we need to copy the code on an arduino, 
* Copy **arduino/leds** and **arduino/library** into your arduino sketchbook
* Upload **leds/leds.ino**

## Components
Here is the list of components, you will need you can easily find it using these keywords on ebay/aliexpress etc...
### led2
* Arduino nano clone CH340G (mini-usb): 2€
### led5
* RobotDyn Nano V3 (micro-usb): 2€
### Strip WS2812B
* 30 leds WS2812B : 4.50€ ( 5 leds :0.75€)
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 9.5€ (2.75€)

## Wiring
![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds_wiring.jpg)
![Inside Led2](https://github.com/madnerdorg/leds/raw/master/doc/leds2_inside.jpg)

### Warning
Do not used more than 5 LEDs without a dedicated power supply or this can damage the LEDs   
Each led can draw up to **60ma** at full brightness   
Arduino can provide up to **500ma** (on 5v/Gnd pin)   
```5 LEDs = 5x60ma = 300ma ```  
Source:
https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections

* D6 --> RESISTOR (470Ohm) DI
* +5V --> 5V
* GND --> GND


# 3D printing
You will have a more uniform light, if you put the case inside another semi-transparent case.    
![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds2.jpg)
![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds5.jpg)    
Downloads Models here : https://github.com/madnerdorg/leds/tree/master/3D    


# Commands available
Here are the commands available, you can send it using Arduino at baudrate 115200.

## Global commands
* /info -------> Give name of device (name:port) (leds:42001)
* /off --> Turn off all leds
* /on --> Turn on all leds
* /status --> Display state of all leds as general_brightness;led0;hue;saturation;value;type_animation;arg1;arg2 etc...
* /load;[status] --> Load the state of leds/animation specified (warning this won't works with 5 leds as the string is too long for serial buffer)
* /save --> Save current state to eeprom
* /reset --> Reset state to eeprom state
* /sync --> Change all value to 255 (max brightness), this will synchronize blink/pulse animation for all leds
* /clear --> Remove settings in eeprom    

### Load example
```
 Fire: load;123;32;255;41;2;0;0;32;255;129;2;0;0;
```
## Leds specific commands
```
color;led;Hue;Saturation;Value ---> Change color for a specific led using hsv
animation;led;type;arg1;arg2 ---> Change animation for a specific led
```
# Color (hue)
Color is hsv have three parameters: hue(color),saturation(more or less white~),value(brightness)
The most important value in hsv is the **hue** which define the color, you can pretty much always use 255;255 for
saturation/value (with the exception of the white color which use 0 as saturation).
* red = 0
* orange = 32
* yellow = 64
* green = 96
* aqua = 128
* blue = 160
* purple = 192
* pink = 224       

## led0 in red 
```
color;0;0;255;255
```
# Animation
* 0: No animation
*  1: Blinking (param1:speed in ms)
*  2: Pulsing
*  3: Rainbow mode
*  4: Alternative Blink (param1:0:master/1:slave, param2:second led/speed in ms)

## led 0 pulsing
```
animation;2;0;0
```
## led 1 blinking at 25ms
```
animation;1;25;0
```
## led 2 rainbow mode (hue change)
```
animation;3;0;0
```
# 

# Licences

## leds.ino
* Author: Rémi Sarrailh (madnerd.org)   
* Licence: MIT

## FastLed
* Main author: Daniel Garcia (fastled)
* Licence: MIT
* Link : https://github.com/FastLED/FastLED

## Cases (stl)
* Author: Olivier Sarrailh
* Licence: CC-by
