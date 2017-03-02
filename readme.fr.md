[English](https://github.com/madnerdorg/leds/)

![Photo leds](https://github.com/madnerdorg/leds/raw/master/doc/universalLed_photo.jpg)   
leds est un périphérique USB crée à partir d'un Arduino nano (clone) tour contrôler facilement 5 leds.     
Démonstration : https://www.youtube.com/watch?v=hgvi46x4oaE

Vous pouvez choisir 6 couleurs pour chaque leds. (Blanc/Rouge/Vert/Bleu/Jaune/Orange/Violet)

# Composants
* Arduino nano CH340G: 2€
* 30 leds WS2812B : 4.50€ ( 5 leds :0.75€)
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 9.5€ (2.75€)

# Branchement
Explication du Branchement : https://www.youtube.com/watch?v=hgvi46x4oaE

N'utilisez pas plus de 5 leds sans une alimentation dédié, ou vous risquez d'endommager les leds
Chaque leds peuvent consommer jusqu'à **60ma** à pleine puissance   
Un Arduino peut fournir jusqu'à **500ma** (sur la broche 5v/Gnd pin)   
```5 leds = 5x60ma = 300ma ```  
Source:
https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections

* D6 --> RESISTANCE (470Ohm) DI
* +5V --> 5V
* GND --> GND

![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/universalLed_wiring.png)

# Impression 3D
Modèle par Olivier Sarrailh : https://github.com/madnerdorg/leds/tree/master/3D    

# Commandes disponibles
Vous pouvez tester ce périphérique dans le moniteur série du logiciel Arduino
Baudrate : 115200 / No Line Ending   

* leds --------> Vérifie si c'est le bon périphérique (et éteint les leds)
* /info -------> Affiche le nom du périphérique : leds
* X:Y -------> Où X est la led et Y la couleur)
* 1:3 -------> (led 1 Vert)

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
Logiciel par Rémi Sarrailh (madnerd.org)   
License: MIT

