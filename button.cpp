#include "button.h"

Button::Button()
{
    sensorType = BUTTON;
    sensorState = UNDEFINED;
    isPushed = false;
    quantity = 0;
}

Button::Button(bool setIsPushed)
{
    sensorType = BUTTON;
    sensorState = UNDEFINED;
    isPushed = setIsPushed;
    quantity = 0;
}

Button::~Button()
{

}

bool Button::getButtonValue()
{
    return this->isPushed;
}

int Button::getValue()
{
   return quantity;
}

void Button::toggleButton()
{
    this->isPushed = !(this->isPushed);
}
