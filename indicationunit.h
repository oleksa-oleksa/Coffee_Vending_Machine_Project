#ifndef INDICATIONUNIT_H
#define INDICATIONUNIT_H
#include "led.h"
#include "lcd_display.h"
#include "drinktype.h"


class IndicationUnit
{
    private:
        class LED sugar;
        class LED milk;
        class LED choice;
        LCD_Display info;

    public:
        IndicationUnit();
        ~IndicationUnit();
        void setChoice(DrinkType drink);
        void incSugar();
        void decSugar();
        void incMilk();
        void decMilk();
};

#endif // INDICATIONUNIT_H
