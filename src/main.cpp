#include <Arduino.h>
#include "TFT_eSPI.h"
#include "240x240 Angie Flower.h"
#include "240x240 abstract 3.h"
/*
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS    16 // Not connected
#define TFT_DC    5
#define TFT_RST   17  // Connect reset to ensure display initialises
*/

#define BL 4
TFT_eSPI tft = TFT_eSPI();  // Invoke custom library 

TFT_eSprite spritte = TFT_eSprite(&tft); // Sprite object "spritte" created

int brightness,fadeAmount = 1,screenW=240, screenH=240; // Screen size


void setup() {
Serial.begin(115200);

pinMode(BL, OUTPUT);
analogWrite(BL, HIGH);
tft.init();
tft.setRotation(1);
tft.setSwapBytes(true);
tft.fillScreen(TFT_BLACK);
Serial.println("ESP START");
}

void loop() {
  tft.pushImage(0, 0, 240, 240, abstract_3);
  analogWrite(BL, brightness ); // Set the LED brightness (0-255)
  brightness = brightness + fadeAmount; // Change the brightness
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse the fade direction
  }
  Serial.println("Hello World");
  delay(10);
  // put your main code here, to run repeatedly:
}

