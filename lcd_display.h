#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <string>
#include "actuator.h"

class LCD_Display: public Actuator
{
    unsigned int xScreenPos = 0;
    unsigned int yScreenPos = 0;
    string title;
    string description;
    string errorMessage;
    double price;

    public:
        LCD_Display();
        ~LCD_Display();
};

#endif // LCD_DISPLAY_H
