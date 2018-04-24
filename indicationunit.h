#ifndef INDICATIONUNIT_H
#define INDICATIONUNIT_H
#include "led.h"


class IndicationUnit
{
public:
    IndicationUnit();
    ~IndicationUnit();
    void setChoice(DrinkType drink);
    void incSugar();
    void decSugar();
    void incMilk();
    void decMilk();

private:
    LED sugar;
    LED milk;
    LED choice;
    Display info;
};

#endif // INDICATIONUNIT_H
