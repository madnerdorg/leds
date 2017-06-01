[English version](https://github.com/madnerdorg/leds/)

![Photo LEDs](https://github.com/madnerdorg/leds/raw/master/doc/leds2.gif)   
**leds** est un appareil USB à base d'arduino nano pour contrôler 1 ou plusieurs LEDS.
Vous pouvez animer chaque leds indépendanments et changer les couleurs en utilisant les couleurs HSV

<!-- TOC -->
- [Télécharger](#télécharger)
- [Applications](#applications)
- [Comment construire leds](#comment-construire-leds)
    - [Arduino](#arduino)
    - [Composants](#composants)
        - [led2](#led2)
        - [led5](#led5)
        - [Strip WS2812B](#strip-ws2812b)
    - [Branchement](#branchement)
        - [Attention!](#attention)
- [Impression 3D](#impression-3d)
- [Commandes disponibles](#commandes-disponibles)
    - [Commandes globales](#commandes-globales)
        - [Example pour load](#example-pour-load)
    - [Commandes pour une led](#commandes-pour-une-led)
- [Couleur (hue)](#couleur-hue)
    - [led0 en red](#led0-en-red)
- [Animation](#animation)
    - [led 0 pulsation](#led-0-pulsation)
    - [led 1 clignotement à 25ms](#led-1-clignotement-à-25ms)
    - [led 2 mode arc en ciel (change hue)](#led-2-mode-arc-en-ciel-change-hue)
- [](#)
- [Licences](#licences)
    - [leds.ino](#ledsino)
    - [FastLed](#fastled)
    - [Boitier (stl)](#boitier-stl)
<!-- /TOC -->

# Télécharger

* [Télécharger l'objet](https://github.com/madnerdorg/leds/archive/master.zip)
* [Télécharger LibreConnect](https://github.com/madnerdorg/libreconnect/releases)
* [Source](https://github.com/madnerdorg/libreconnect/releases)

# Applications
Requis [LibreConnect](https://github.com/madnerdorg/libreconnect/releases)

* [apps/html](https://github.com/madnerdorg/leds/tree/master/apps)  
Paramètrer vos leds à l'aide d'une page web, une fois que vous satisfait de la manière dont vos leds brillent, vous
pouvez sauvegarder l'état et l'arduino se souviendra de l'état actuel.
Vous pouvez ainsi l'utiliser n'importe où!
![Photo LEDs](https://github.com/madnerdorg/leds/raw/master/doc/leds_html.jpg)   

* [apps/tasker](https://github.com/madnerdorg/leds/tree/master/apps)    
Soyez notifié quand quelqu'un vous appelle, grâce à tasker à l'aide de scripts tout simple en javascript.
Grâce à la puissance de tasker, vous pouvez synchroniser les leds lorsqu'il se passe des choses sur votre téléphone!

* apps/thunderbird [TODO]    
Soyez notifié quand quelqu'un vous envoie un email, à l'aide des **filtres** et du plugin **mail alerts**.

# Comment construire leds

## Arduino
Tout d'abord nous devons copier le code sur un arduino,
* Copier **arduino/leds** et **arduino/library** dans votre carnet de croquis arduino
* Téléverser **leds/leds.ino**

## Composants
Voici la liste des composants , vous pouvez facilement les trouvers sur ebay/aliexpress grâce à ses mots-clés.
### led2
* RobotDyn Nano V3 (micro-usb): 2€
### led5
* Arduino nano clone CH340G (mini-usb): 2€
### Strip WS2812B
* 30 leds WS2812B : 4.50€ ( 5 leds :0.75€)
* Resistor pack 400pcs (3€) (1 resistor: 0.0071€)
* Total : 9.5€ (2.75€)

## Branchement
![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds_wiring.jpg)
![Inside Led2](https://github.com/madnerdorg/leds/raw/master/doc/leds2_inside.jpg)

### Attention!
Evitez d'utiliser plus de 5 LEDS sans une alimentation dédié, où vous risquez d'abimer vos LEDS.
Chaque leds consomme à peu près **60ma** lorsqu'elle sont complètement allumée
Source:
https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections

* D6 --> RESISTANCE (470Ohm) DI
* +5V --> 5V
* GND --> GND

# Impression 3D
Afin d'avoir une lumière uniforme, vous pouvez utiliser un boitier semi-transparent en plus du boitier.
![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds2.jpg)
![Wiring_leds](https://github.com/madnerdorg/leds/raw/master/doc/leds5.jpg)    
Télécharger les modèles ici: https://github.com/madnerdorg/leds/tree/master/3D    

# Commandes disponibles
Voici les commandes disponibles, vous pouvez les envoyer en utilisant le logiciel Arduino (baudrate 115200)

## Commandes globales
* /info -------> Donne le nom de l'appareil (nom:port) (leds:42001)
* /off --> Eteint toutes les leds
* /on --> Allume toutes les leds
* /status --> Affiche l'état des leds sous cette forme: general_brightness;led0;hue;saturation;value;type_animation;arg1;arg2 etc...
* /load;[status] --> Charge un état des leds (attention, le buffer série n'est pas assez performant pour gérer 5 leds)
* /save --> Sauvegarde l'état actuel des leds dans la mémoire de l'arduino (eeprom)
* /reset --> Remet l'état à celui sauvegrder dans l'eeprom
* /sync --> Change value à 255 (luminosité à fond), ceci a pour effet de resynchroniser chaque animations pour les leds.
* /clear --> Efface l'état des leds sauvegarder dans l'eeprom.

### Example pour load
```
 Fire: load;123;32;255;41;2;0;0;32;255;129;2;0;0;
```
## Commandes pour une led
```
color;led;Hue;Saturation;Value ---> Change la couleur pour une led
animation;led;type;arg1;arg2 ---> Change l'animation pour une led
```
# Couleur (hue)
Les couleurs exprimés en HSV ont trois paramètres: hue(couleur), saturation(plus ou moins blanc), value(luminosité)
La valeur la plus important est le **hue** car elle définit la couleur, à l'exception du blanc (qui utilise la saturation à 0), vous pouvez
pratiquement mettre uniquement 255;255 pour value et saturation.
* rouge = 0
* orange = 32
* jaune = 64
* vert = 96
* aqua = 128
* bleu = 160
* violet = 192
* rose = 224       

## led0 en red 
```
color;0;0;255;255
```
# Animation

![Photo LEDs](https://github.com/madnerdorg/leds/raw/master/doc/leds5.gif)  
*  0: Pas d'animation
*  1: Clignotement (param1:vitesse en ms)
*  2: Pulsation
*  3: Mode arc-en-ciel
*  4: Clignotement alterné (param1:0:maitre/1:esclave, param2:position led esclave/vitesse en ms)

## led 0 pulsation
```
animation;2;0;0
```
## led 1 clignotement à 25ms
```
animation;1;25;0
```
## led 2 mode arc en ciel (change hue)
```
animation;3;0;0
```
# 

# Licences

## leds.ino
* Auteur: Rémi Sarrailh (madnerd.org)   
* Licence: MIT

## FastLed
* Auteur principale: Daniel Garcia (fastled)
* Licence: MIT
* Link : https://github.com/FastLED/FastLED

## Boitier (stl)
* Auteur: Olivier Sarrailh
* Licence: CC-by
