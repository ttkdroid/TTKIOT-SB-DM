#include "leds.h"

// TTKIOT-SB-DM comes with 10 onboard LEDs strip on Pin 23
#define NUM_LEDS 10

// Create the FASTLEd object
CRGB leds[NUM_LEDS];

// set DefaultBrightness
int defaultBrightness = 15;

void ledSetup()
{
  FastLED.addLeds<NEOPIXEL, TTKIOT_RGB_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(defaultBrightness);
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  delay(1000);
  circle(0, 255, 0);
}

void police(int brightness)
{
  FastLED.setBrightness(brightness);
  int bltime = 50;
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  for (size_t i = 0; i < 3; i++)
  {

    for (size_t i = 0; i < 12; i++)
    {
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Red;
      leds[3] = CRGB::Red;
      leds[4] = CRGB::Red;
      leds[5] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[9] = CRGB::Black;
      FastLED.show();
      delay(bltime);
      for (size_t i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Black;
      }
      FastLED.show();
      delay(bltime);
    }
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    delay(20);
    for (size_t i = 0; i < 12; i++)
    {
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[5] = CRGB::Blue;
      leds[6] = CRGB::Blue;
      leds[7] = CRGB::Blue;
      leds[8] = CRGB::Blue;
      leds[9] = CRGB::Blue;
      FastLED.show();
      delay(bltime);
      for (size_t i = 0; i < NUM_LEDS; i++)
      {
        leds[i] = CRGB::Black;
      }
      FastLED.show();
      delay(bltime);
    }
  }
  FastLED.setBrightness(defaultBrightness);
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void police2(int brightness)
{
  for (size_t i = 0; i < 5; i++)
  {
    blueBlink(brightness);
    delay(50);
    redBlink(brightness);
    delay(50);
  }
}

void redBlink(int brightness)
{
  FastLED.setBrightness(brightness);
  for (size_t i = 0; i < 7; i++)
  {
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    delay(80);
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Red;
    }
    FastLED.show();
    delay(80);
  }
  FastLED.setBrightness(defaultBrightness);
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void blueBlink(int brightness)
{
  FastLED.setBrightness(brightness);
  for (size_t i = 0; i < 7; i++)
  {
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    delay(80);
    for (size_t i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Blue;
    }
    FastLED.show();
    delay(80);
  }
  FastLED.setBrightness(defaultBrightness);
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void circle(int r, int g, int b)
{
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i].setRGB(r, g, b);
    FastLED.show();
    delay(80);
  }
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(80);
  }
}

void circleBack(int r, int g, int b)
{
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[9 - i].setRGB(r, g, b);
    FastLED.show();
    delay(80);
  }
  for (size_t i = 0; i < NUM_LEDS; i++)
  {
    leds[9 - i] = CRGB::Black;
    FastLED.show();
    delay(80);
  }
}

void showRandom()
{
  leds[random(0, 9)].setRGB(random(1, 255), random(1, 255), random(1, 255));
  FastLED.show();
  delay(50);
  leds[random(0, 9)] = CRGB::Black;
  FastLED.show();
  delay(50);
}