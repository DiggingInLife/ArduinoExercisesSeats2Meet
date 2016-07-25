
#include <FastLED.h>
#define NUM_LEDS 30
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
void loop() { 
  leds[0] = CRGB::Red; 
  FastLED.show(); 
  delay(30); 
}
