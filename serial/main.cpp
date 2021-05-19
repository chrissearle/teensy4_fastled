#include <Arduino.h>

#include <WS2812Serial.h>
#define USE_WS2812SERIAL

#define FASTLED_INTERNAL
#include <FastLED.h>

#define NUM_LEDS 240

#define LED_PIN 1

CRGB leds[NUM_LEDS];

int offset = 0;

void setup()
{
  FastLED.addLeds<WS2812SERIAL, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop()
{
  uint16_t sinBeat = beatsin16(5, 0, NUM_LEDS - 1, 0, 0);
  uint8_t sinBeat2 = beatsin8(7, 0, 255, 0, 0);

  leds[sinBeat] = CHSV(sinBeat2, 255, 255);

  fadeToBlackBy(leds, NUM_LEDS, 1);

  FastLED.show();
}
