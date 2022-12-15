#ifndef __LEDS_H
#define __LEDS_H
#include "pindefs.h"
#include "<FastLED.h>"


void ledSetup();
void police(int brightness);
void police2(int brightness);
void redBlink(int brightness);
void blueBlink(int brightness);
void circle(int r, int g, int b);
void circleBack(int r, int g, int b);
void showRandom();

#endif