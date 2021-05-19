## Teensy 4 + FastLED

Getting Teensy 4.0 to play with FastLED using WS2812Serial and OctoWS2811 libraries.

Never managed to get Teensy 4.0 to play nicely with vanilla FastLED - either the entire strip lights white or a sequence starts but then hangs.

Two options that do work:

* WS2812Serial - use the version that comes with teensyduino
* Combine with OctoWS2811 - use the latest github version

### WS2812Serial

You must use a specific pin - from [this example](https://github.com/PaulStoffregen/WS2812Serial/blob/master/examples/FastLED_Cylon/FastLED_Cylon.ino):

```
// Usable pins:
//   Teensy LC:   1, 4, 5, 24
//   Teensy 3.2:  1, 5, 8, 10, 31   (overclock to 120 MHz for pin 8)
//   Teensy 3.5:  1, 5, 8, 10, 26, 32, 33, 48
//   Teensy 3.6:  1, 5, 8, 10, 26, 32, 33
//   Teensy 4.0:  1, 8, 14, 17, 20, 24, 29, 39
//   Teensy 4.1:  1, 8, 14, 17, 20, 24, 29, 35, 47, 53
```

* [platformio configuration](serial/platformio.ini)
* [Main program](serial/main.cpp)

### OctoWS2811

Can use any pins and can use parallel.

Based on [this post](https://blinkylights.blog/2021/02/03/using-teensy-4-1-with-fastled/) but switched from RGB to GRB.

* [platformio configuration](octo/platformio.ini)
* [Main program](octo/main.cpp)
* [CTeensy4Controller](octo/CTeensy4Controller.h)
