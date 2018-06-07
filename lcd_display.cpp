#include "lcd_display.h"

LCD_Display::LCD_Display()
{
    //actuator_duration
    actuator_Type = LCD;
    actuator_state = UNDEFINED;
}

LCD_Display::~LCD_Display()
{
  //to implement
}

ActuatorType LCD_Display::getActuatorType() const
{
    return actuator_Type;
}

unsigned int LCD_Display::getActuatorDuration() const
{
    return actuator_duration;
}

State LCD_Display::getActuatorState() const
{
    return actuator_state;
}

unsigned int LCD_Display:: get_xScreenPos() const
{
    return xScreenPos;
}

unsigned int LCD_Display::get_yscreenPos() const
{
    return yScreenPos;
}

string LCD_Display::get_title() const
{
    return title;
}

string LCD_Display::get_description() const
{
    return description;
}

string LCD_Display::get_errorMessage() const
{
    return errorMessage;
}

void LCD_Display::setActuatorState(State actuator_state)
{
    this->actuator_state = actuator_state;
}

void LCD_Display::setActuatorDuration(unsigned int actuator_duration)
{
    this->actuator_duration = actuator_duration;
}

void LCD_Display::setActuatorType(ActuatorType actuator_Type)
{
  this->actuator_Type = actuator_Type;
}














