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

Button::~Button()
{

}

bool Button::getButtonValue()
{
    return this->isPushed;
}

void Button::toggleButton()
{
    this->isPushed = !(this->isPushed);
}
