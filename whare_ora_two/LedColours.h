#include <Adafruit_NeoPixel.h>
#include "SensorConfig.h"
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, NEOPIXELS_PIN, NEO_RGB + NEO_KHZ800);

uint32_t magenta = strip.Color(255, 0, 255);
uint32_t green = strip.Color(0, 255, 0);
uint32_t red = strip.Color(255, 0, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t white = strip.Color(255, 255, 255);
uint32_t yellow = strip.Color(255, 100, 0);
uint32_t aqua = strip.Color(0, 255, 100);
uint32_t nolight = strip.Color(0, 0, 0);


int TempThresholds;


void turnOffLeds() {
  strip.setPixelColor(NEOPIXEL_LED_T, nolight);
  strip.setPixelColor(NEOPIXEL_LED_H, nolight);
  strip.setPixelColor(NEOPIXEL_LED_P, nolight);
  strip.show();
}


void setupLeds() {
  //set up neopixel
  strip.begin();
  strip.setBrightness(64);
  strip.show(); // Initialize all pixels to 'off'
}


void lightUpLeds(float temperature, float humidity, float soil) {

  Serial.print("Temp");
  if (temperature > 28) {
    strip.setPixelColor(NEOPIXEL_LED_T, red);
  }
  else if (temperature > 26) {
    strip.setPixelColor(NEOPIXEL_LED_T, magenta);
  }
  else if (temperature >= 18.5) {
    strip.setPixelColor(NEOPIXEL_LED_T, nolight);
  }
  else if (temperature >= 16) {
    strip.setPixelColor(NEOPIXEL_LED_T, aqua);
  }
  else {
    strip.setPixelColor(NEOPIXEL_LED_T, blue);
  }

  Serial.print("humidity");
  if (humidity < 30) {
    Serial.println("red");
    strip.setPixelColor(NEOPIXEL_LED_H, red);
  }
  else if (humidity <= 85) {
    strip.setPixelColor(NEOPIXEL_LED_H, nolight);
  }
  else {
    strip.setPixelColor(NEOPIXEL_LED_H, blue);
  }

  if (soil <=600) {
    strip.setPixelColor(NEOPIXEL_LED_P, red);
  }
  else if (soil <=600) {
    strip.setPixelColor(NEOPIXEL_LED_P, yellow);
  }
  else if (soil <= 9000) {
    strip.setPixelColor(NEOPIXEL_LED_P, nolight);
  }
  else {
    strip.setPixelColor(NEOPIXEL_LED_P, blue);
  }
 
  strip.show();
}

