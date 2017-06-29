// LibreLeds

#include <FastLED.h>
#include <EEPROM.h>

/*
  Animation
  0: No animation
  1: Blinking (param1:speed in ms)
  2: Pulsing
  3: Rainbow mode
  4: Alternative Blink (param1:master/slave, param2:led/speed in ms)
*/

// Settings
const String usb_name = "leds:42001";
const int NUM_LEDS = 2;

//Leds Setup
const int DATA_PIN = 6; //WS2812b led

//Constants animation
const int STOP = 0;
const int BLINK = 1;
const int PULSE = 2;
const int RAINBOW = 3;
const int ALTERNATE_BLINK = 4;

const int MASTER = 0;
const int SLAVE = 1;

//Leds objects
CRGB leds[NUM_LEDS];

//Leds Settings
int hue[NUM_LEDS];
int sat[NUM_LEDS];
int val[NUM_LEDS];
int brightness;

// Animation Settings
int anim[NUM_LEDS];
int params1[NUM_LEDS];
int params2[NUM_LEDS];

// Leds Status
int status[NUM_LEDS];
long timing[NUM_LEDS];

// Serial Settings
String command;
String readString; //String Buffer

//Timing
unsigned long currentTime = 0;
unsigned long previousTime = 0;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(115200);
  init_leds();
}

void loop() {
  animation_loop();
  FastLED.show();
  serialManager();
}


//Equivalent of explode in PHP (use for serial commands parsing)
String splitString(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void change_color_all(int h, int s, int v) {
  for (int i = 0; i < NUM_LEDS; i++) {change_color(i, h, s, v);}
}

void change_color(int led, int h, int s, int v) {
  leds[led] = CHSV(h, s, v);
  hue[led] = h;
  sat[led] = s;
  val[led] = v;
}

void change_anim_all(int animation, int parameter1, int parameter2) {
  for (int led = 0; led < NUM_LEDS; led++) {change_anim(led, animation, parameter1 , parameter2);}
}

void change_anim(int led, int animation, int parameter1, int parameter2) {
  anim[led] = animation;
  params1[led] = parameter1;
  params2[led] = parameter2;
  status[led] = 0;
  timing[led] = 0;
}


void animation_loop() {
  currentTime = millis();
  for (int led = 0; led < NUM_LEDS; led++) {

    // Pulse animation
    if (anim[led] == PULSE) {
      //Orientation (fading in/fading out)
      if (val[led] <= 0) {status[led] = 1;}
      if (val[led] >= 255) {status[led] = 0;}
      if (status[led] == 0) {val[led]--;} else {val[led]++;}
      change_color(led, hue[led], sat[led], val[led]);
      //Serial.println(val[led]);
    }

    //Blink animation
    if (anim[led] == BLINK) {
      //If interval is finish change state
      if (currentTime - timing[led] > params1[led]) {
        timing[led] = currentTime;
        if (val[led] == 255) {val[led] = 0;} else {val[led] = 255;}
        change_color(led, hue[led], sat[led], val[led]);
      }
    }

    if (anim[led] == RAINBOW) {
      if (hue[led] <= 0) {status[led] = 1;}
      if (hue[led] >= 255) {status[led] = 0;}
      if (status[led] == 0) {hue[led]--;} else {hue[led]++;}
      change_color(led, hue[led], sat[led], val[led]);
    }

    if (anim[led] == ALTERNATE_BLINK) {
      //If led is master (ignore if slave)
      if (params1[led] == 0) {
        int led2 = params2[led];
        int interval = params2[led2];
        if (currentTime - timing[led] > interval) {
          timing[led] = currentTime;
          if (val[led] == 255) {
            val[led] = 0;
            val[led2] = 255;
          } else {
            val[led] = 255;
            val[led2] = 0;
          }
        }
        change_color(led, hue[led], sat[led], val[led]);
        change_color(led2, hue[led2], sat[led2], val[led2]);
      }
    }
  }
}

void init_leds() {
  int status_eeprom;
  EEPROM.get(0,status_eeprom);
  if(status_eeprom != -1){
    read_eeprom();
  } else {
    change_color_all(0, 0, 0);
    change_anim_all(0, 0, 0);
    brightness = 255;
    LEDS.setBrightness(255);
  }
}

void read_eeprom(){
  int address = 0;
  EEPROM.get(0,brightness);
  LEDS.setBrightness(brightness);
  address = 2;
  for (int led = 0; led < NUM_LEDS; led++) {
    EEPROM.get(address,hue[led]);
    address = address + 2;
    EEPROM.get(address,sat[led]);
    address = address + 2;
    EEPROM.get(address,val[led]);
    address = address + 2;
    EEPROM.get(address,anim[led]);
    address = address + 2;
    EEPROM.get(address,params1[led]);
    address = address + 2;
    EEPROM.get(address,params2[led]);
    address = address + 2;
    change_color(led, hue[led], sat[led], val[led]);
    change_anim(led, anim[led], params1[led], params2[led]);
  }
}

void save_eeprom(){
  int address = 0;
  EEPROM.put(0,brightness);
  address = 2;
  for (int led = 0; led < NUM_LEDS; led++) {
    EEPROM.put(address,hue[led]);
    address = address + 2;
    EEPROM.put(address,sat[led]);
    address = address + 2;
    EEPROM.put(address,val[led]);
    address = address + 2;
    EEPROM.put(address,anim[led]);
    address = address + 2;
    EEPROM.put(address,params1[led]);
    address = address + 2;
    EEPROM.put(address,params2[led]);
    address = address + 2;
  }
  //Serial.println("Saved eeprom");
}

void serialManager() {
  while (Serial.available()) {delay(5);if (Serial.available() > 0) {char c = Serial.read();readString += c;}}

  if (readString.length() > 0) {
    if (readString[0] == '/'){
        if (readString == "/info") {
          Serial.println(usb_name);
        } 
      //Get status
        if (readString == "/status") {
          Serial.print(brightness);
          Serial.print(";");
          for (int led = 0; led < NUM_LEDS; led++) {
           Serial.print(hue[led]);
           Serial.print(";");
           Serial.print(sat[led]);
           Serial.print(";");
           Serial.print(val[led]);
           Serial.print(";");
           Serial.print(anim[led]);
           Serial.print(";");
           Serial.print(params1[led]);
           Serial.print(";");
           Serial.print(params2[led]);
           Serial.print(";");
          }
          Serial.println();
        }

     
        if (readString == "/save") {
          save_eeprom();
          Serial.println(readString);
        }
        
        //Turn off all leds
        if (readString == "/off") {
          change_color_all(0, 0, 0);
          change_anim_all(0, 0, 0);
          Serial.println(readString);
        }

       if (readString == "/on") {
          change_color_all(0,0, 255);
          change_anim_all(0, 0, 255);
          Serial.println(readString);
        }

          if (readString == "/sync"){
           for (int led = 0; led < NUM_LEDS; led++) {
              val[led] = 255;
           }
           Serial.println(readString);
        }

        if (readString == "/reset"){
          read_eeprom();
        }

        if (readString == "/clear"){
          change_color_all(0, 0, 0);
          change_anim_all(0, 0, 0);
          LEDS.setBrightness(255);
          save_eeprom();
          Serial.println(readString);
        }
    } else {
          String command = splitString(readString, ';', 0);

          //Change brightness
          if (command == "brightness") {
            brightness = splitString(readString, ';', 1).toInt();
            LEDS.setBrightness(brightness);
            Serial.println(readString);
          }

          //Change color
          if (command == "color") {
            int led = splitString(readString, ';', 1).toInt();
            int h = splitString(readString, ';', 2).toInt();
            int s = splitString(readString, ';', 3).toInt();
            int v = splitString(readString, ';', 4).toInt();
            change_color(led, h, s, v);
            //If we turn off led we assume we want to stop the animation too.
            if ( (h==0) && (s==0) && (v==0) ) {
              change_anim(led,0,0,0);
            }
            Serial.println(readString);
          }
          
          //Change animation
          if (command == "animation") {
            int led = splitString(readString, ';', 1).toInt();
            int animation = splitString(readString, ';', 2).toInt();
            int parameter1 = splitString(readString, ';', 3).toInt();
            int parameter2 = splitString(readString, ';', 4).toInt();
            change_anim(led, animation, parameter1, parameter2);
            //Start Rainbow animation with red 
            if(animation == 3){
              change_color(led,0,255,255);
            }
            Serial.println(readString);
          }

          //Load previous state
          if (command == "load"){
             int cursor = 1;
             brightness = splitString(readString, ';', cursor++).toInt();
            
             for (int led = 0; led < NUM_LEDS; led++) {
                  int h = splitString(readString, ';', cursor).toInt();
                  cursor++;
                  int s = splitString(readString, ';', cursor).toInt();
                  cursor++;
                  int v = splitString(readString, ';', cursor).toInt();
                  cursor++;
                  int animation = splitString(readString, ';', cursor).toInt();
                  cursor++;
                  int parameter1 = splitString(readString, ';', cursor).toInt();
                  cursor++;
                  int parameter2 = splitString(readString, ';', cursor).toInt();
                  cursor++;
                  change_color(led,h,s,v);
                  change_anim(led, animation, parameter1, parameter2);
             }
             Serial.println(readString);
          }
          
        }
    readString = "";
  }
}




