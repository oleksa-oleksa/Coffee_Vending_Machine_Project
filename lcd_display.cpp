#include "lcd_display.h"

LCD_Display::LCD_Display()
{
    //actuator_duration
    actuatorType = LCD;
    actuatorState = UNDEFINED;
}

LCD_Display::~LCD_Display()
{
  //to implement
}


unsigned int LCD_Display:: getXScreenPos() const
{
    return xScreenPos;
}

unsigned int LCD_Display::getYscreenPos() const
{
    return yScreenPos;
}

string LCD_Display::getTitle() const
{
    return title;
}

string LCD_Display::getDescription() const
{
    return description;
}

string LCD_Display::getErrorMessage() const
{
    return errorMessage;
}

double LCD_Display::getPrice() const
{
    return price;
}

void LCD_Display::setTitle(string title)
{
    this->title = title;
}

void LCD_Display::setDescription(string description)
{
    this->description = description;
}

void LCD_Display::setXScreenPos(unsigned int xScreenPos)
{
    this->xScreenPos = xScreenPos;
}

void LCD_Display::setYScreenPos(unsigned int yScreenPos)
{
    this->yScreenPos = yScreenPos;
}

void LCD_Display::setPrice(double price)
{
    this->price = price;
}

void LCD_Display::setErrorMessage(string errorMessage)
{
    this->errorMessage = errorMessage;
}
