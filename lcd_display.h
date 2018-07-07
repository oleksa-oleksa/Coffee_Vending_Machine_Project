#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <string>
#include "actuator.h"
#include "QString"
#include "userchoice.h"
#include "preparationstatus.h"

using namespace std;

enum LCD_Message {
    DEFAULT,
    GREETING,
    USER_CHOICE,
    ERROR,
    WAIT_PLEASE,
    TAKE_YOUR_DRINK,
    SYSTEM_ERROR,
    PAYMENT_ERROR
};

class LCD_Display : public Actuator
{
    private:

        QString title;
        QString drinkName;
        double price;
        bool isBacklit;

    public:
        LCD_Display();
        virtual ~LCD_Display();

        QString getTitle();
        void setTitle(QString title);
        QString getDrinkName();
        void setDrinkName(QString drinkName);
        double getPrice();
        void setPrice(double price);
        void setBacklight(bool isBacklit);
        bool getBacklight();

        void writeDefaultText(UserChoice *activeUserChoice);
        void writeGreetingText(UserChoice *activeUserChoice);
        void writeCardErrorText();
        void writeUserChoiceText(UserChoice *activeUserChoice);
        void writeSystemErrorMessage(PreparationStatus message);
        void writeTakeDrinkMessage();
        void writeWaitText();
        QString printMessage(PreparationStatus status);

};

#endif // LCD_DISPLAY_H
