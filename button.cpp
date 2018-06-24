#include "button.h"

Button::Button()
{
    sensorType = BUTTON;
    sensorState = UNDEFINED;
    isPushed = false;
}

Button::Button(bool setIsPushed)
{
    sensorType = BUTTON;
    sensorState = UNDEFINED;
    isPushed = setIsPushed;
}

bool Button::getButtonValue()
{
    return this->isPushed;
}

void Button::toggleButton()
{
    this->isPushed = !(this->isPushed);
}

void Button::setSensorstate(State newState)
{
   if (newState == PRESSED)
   {
        isPushed = true;
   }
   if (newState == RELEASED)
   {
        isPushed = false;
   }
   if (newState == UNDEFINED)
   {
        isPushed = false; // released if undefined
   }
}
