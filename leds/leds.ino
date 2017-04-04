#include <FastLED.h>
/*
  Universal USB LED
  https://github.com/madnerdorg/leds
  -----------------
  Components:
  WS2812b led (NEOPIXEL clone)
  Arduino Nano (clone)

  Wiring
  D6 (480Ohm resistor) ---> DI

   Color Table
   0 Off
   1 White
   2 Red
   3 Green
   4 Blue
   5 Yellow
   6 Orange
   7 Purple
*/

//USB Device Type
const String usb_name = "leds:42001";

//Leds Setup
const int DATA_PIN = 6; //WS2812b led
const int NUM_LEDS = 5;

CRGB leds[NUM_LEDS];

int leds_state[NUM_LEDS] = {0, 0, 0, 0, 0};

//Serial string buffer
String readString;

// Serial

//When application asked if this is the correct arduino
void serialCheck() {
  if (readString == "/info") {
    Serial.println(usb_name);
  } else {
  for (int i = 0; i < NUM_LEDS; i++) {
      leds_state[i] = splitString(readString, ';', i).toInt();
      changeLed(i, leds_state[i]);
      Serial.print(leds_state[i]);
      if (i != (NUM_LEDS - 1)) {
        Serial.print(";");
      }

    }
    Serial.println();
  }
}

//Convert characters sent by serial to string
void serialManager() {
  //Get Serial as a string
  while (Serial.available()) {
    delay(3); // Wait for data

    //Convert to String
    if (Serial.available() > 0) {
      char c = Serial.read();
      readString += c;
    }
  }
}

// Leds

//You can change/add color here
void changeLed(int pos, int color) {
  switch (color) {
    case 0:
      leds[pos] = CRGB::Black;
      break;
    case 1:
      leds[pos] = CRGB::White;
      break;
    case 2:
      leds[pos] = CRGB::Red;
      break;
    case 3:
      leds[pos] = CRGB::Green;
      break;
    case 4:
      leds[pos] = CRGB::Blue;
      break;
    case 5:
      leds[pos] = CRGB::Yellow;
      break;
    case 6:
      leds[pos] = CRGB::Orange;
      break;
    case 7:
      leds[pos] = CRGB::Purple;
      break;
  }
  leds_state[pos] = color;
  FastLED.show();
}

//Blinks leds
void BlinkLeds(int color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    changeLed(i, color);
  }

  delay(100);
  for (int i = 0; i < NUM_LEDS; i++) {
    changeLed(i, 0);
  }
}

void setup() {
  // Setup Led
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // Test Led (All White)
  for (int i = 0; i < NUM_LEDS; i++) {
    changeLed(i, 1);
  }

  //Setup Serial
  Serial.begin(115200);
}

void loop() {
  serialManager();
  //Serial.println(readString); //Show order sent

  //If string received
  if (readString.length() > 0) {
    serialCheck();

    //We clean the serial buffer
    readString = "";
  }
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





