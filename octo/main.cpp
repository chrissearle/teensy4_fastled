#include <Arduino.h>
#include <OctoWS2811.h>

#define FASTLED_INTERNAL
#include <FastLED.h>

#include "CTeensy4Controller.h"

const int numPins = 1;
byte pinList[numPins] = {1};

const int ledsPerStrip = 240;
CRGB leds[numPins * ledsPerStrip];

// These buffers need to be large enough for all the pixels.
// The total number of pixels is "ledsPerStrip * numPins".
// Each pixel needs 3 bytes, so multiply by 3.  An "int" is
// 4 bytes, so divide by 4.  The array is created using "int"
// so the compiler will align it to 32 bit memory.
DMAMEM int displayMemory[ledsPerStrip * numPins * 3 / 4];
int drawingMemory[ledsPerStrip * numPins * 3 / 4];

OctoWS2811 octo(ledsPerStrip, displayMemory, drawingMemory, WS2811_GRB | WS2811_800kHz, numPins, pinList);

CTeensy4Controller<GRB, WS2811_800kHz> *pcontroller;

void setup()
{
  octo.begin();
  pcontroller = new CTeensy4Controller<GRB, WS2811_800kHz>(&octo);

  FastLED.setBrightness(50);
  FastLED.addLeds(pcontroller, leds, numPins * ledsPerStrip);
}

void loop()
{
  uint16_t sinBeat = beatsin16(5, 0, (numPins * ledsPerStrip) - 1, 0, 0);
  uint8_t sinBeat2 = beatsin8(7, 0, 255, 0, 0);

  leds[sinBeat] = CHSV(sinBeat2, 255, 255);

  fadeToBlackBy(leds, (numPins * ledsPerStrip), 1);

  FastLED.show();
}
