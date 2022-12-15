#include "button.h"
#include "leds.h"

int loopCounter = 0;
bool buttonPressed = false;
void buttonSetup()
{    
    pinMode(TTKIOT_BUTTON_PIN, INPUT);
    attachInterrupt(TTKIOT_BUTTON_PIN, buttonPress, CHANGE);
}

void buttonPress()
{
    buttonPressed = true;
}

void myAlarm()
{
    if (loopCounter > 100)
    {
        police2(255);
    }
    else
    {
        police(255);
    }
}

void buttonRun()
{
    if (buttonPressed)
    { 
        myAlarm();
    }
    buttonPressed = false;
    if (loopCounter == 50)
    {
        circleBack(random(1, 255), random(1, 255), random(1, 255));
    }
    if (loopCounter == 100)
    {
        circle(random(1, 255), random(1, 255), random(1, 255));
    }
    if (loopCounter == 150)
    {
        circleBack(random(1, 255), random(1, 255), random(1, 255));
        loopCounter = 0;
    }
    loopCounter++;
}