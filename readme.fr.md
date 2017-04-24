[English Version](https://github.com/madnerdorg/leds/)

![Photo LED](https://github.com/madnerdorg/leds/raw/master/doc/leds.jpg)   
LED est un périphérique USB à base d'Arduino nano (clone) pour facilement contrôler 5 LED.

# Utilisation
* Copier **libraries/LED** dans votre carnet de croquis
* Téléverser **leds/leds.ino**
* Aller sur  [TODO]

![colors](https://github.com/madnerdorg/leds/raw/master/doc/leds_colors.png)

# Composants
* Arduino nano CH340G: 2€
* 30 leds WS2812B : 4.50€ ( 5 leds :0.75€)
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 9.5€ (2.75€)

# Branchement
[![](https://i.ytimg.com/vi/qI0uImQtrG4/hqdefault.jpg?custom=true&w=336&h=188&stc=true&jpg444=true&jpgq=90&sp=67&sigh=6iUeWMWgQiv0QX4oDcuzS7znghM)](https://www.youtube.com/watch?v=qI0uImQtrG4)      
N'utilisez pas plus de 5 LED sans une alimentation dédiée où cela pourrait endommager vos LED
Chaque LED peut consommer jusqu'à **60ma** lorsqu'elles sont à leur luminosité maximale.
Un arduino peut fournir jusqu'à **500ma** (sur 5v)
```5 LED = 5x60ma = 300ma ```  
Source:
https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections

* D6 --> RÉSISTANCE (470Ohm) DI
* +5V --> 5V
* GND --> GND

![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds_wiring.jpg)

# Modèle 3D
Modèles 3D faits par Olivier Sarrailh : https://github.com/madnerdorg/leds/tree/master/3D    

# Commandes disponibles
* /info -------> donne le nom du périphérique (nom:port) (leds:42001)
* A;B;C;D;E -------> (Où A est la couleur de la led1, etc...)
* 0 ---> éteins toutes les LED

# Color
* 0 : OFF
* 1 : Blanc/ON
* 2 : Rouge
* 3 : Vert
* 4 : Bleu
* 5 : Jaune
* 6 : Orange
* 7 : Violet

# Licences

## leds.ino
* Auteur: Rémi Sarrailh (madnerd.org)   
* Licence: MIT

## FastLed
* Auteur principal: Daniel Garcia (fastled)
* Licence: MIT
* Lien : https://github.com/FastLED/FastLED

