#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <string>
#include "actuator.h"
#include "QString"
#include "userchoice.h"

using namespace std;

class LCD_Display : public Actuator
{
    private:

        QString title;
        QString drinkName;
        double price;

    public:
        LCD_Display();
        virtual ~LCD_Display();

        QString getTitle();
        void setTitle(QString title);
        QString getDrinkName();
        void setDrinkName(QString drinkName);
        double getPrice();
        void setPrice(double price);

        void writeDefaultText(UserChoice *activeUserChoice);
        void writeGreetingText(UserChoice *activeUserChoice);
        void writeErrorText(UserChoice *activeUserChoice);



};

#endif // LCD_DISPLAY_H
