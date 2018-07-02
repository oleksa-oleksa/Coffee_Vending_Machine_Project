#include "lcd_display.h"
#include <QDebug>

LCD_Display::LCD_Display()
{
    //actuator_duration
    actuatorType = LCD;
    actuatorState = UNDEFINED;
}

LCD_Display::~LCD_Display()
{

}


QString LCD_Display::getTitle()
{
    return title;
}

void LCD_Display::setTitle(QString title)
{
    this->title = title;
    qDebug() << "LCD: " << title;
}

QString LCD_Display::getDrinkName()
{
    return drinkName;
}

void LCD_Display::setDrinkName(QString drinkName)
{
    this->drinkName = drinkName;
    qDebug() << "LCD: You have selected: " <<  this->drinkName;

}

double LCD_Display::getPrice()
{
    return price;
}

void LCD_Display::setPrice(double price)
{
    this->price = price;
    qDebug() << "LCD: You have to pay " << price << "for your drink!";
}

void LCD_Display::writeDefaultText(UserChoice *activeUserChoice)
{
    setTitle("Please insert card");
    if (activeUserChoice->getSelectedDrink() == NO_DRINK)
    {
        setDrinkName("NO_DRINK");
        setPrice(0.0);
    }
    else
    {
        setDrinkName(activeUserChoice->printSelectedDrink());
        setPrice(activeUserChoice->getPrice());
    }

}

void LCD_Display::writeGreetingText(UserChoice *activeUserChoice)
{
    QString str = activeUserChoice->getCard()->getAccount()->getOwner()->getName().c_str();
    setTitle("Nice to see you again, " + str);
    setDrinkName("Nothing");
    setPrice(activeUserChoice->getPrice());

}

void LCD_Display::writeErrorText()
{
    setTitle("Not a valid card! Aborted...");
    setDrinkName("NO_DRINK");
    setPrice(0.0);
}

void LCD_Display::writeUserChoiceText(UserChoice *activeUserChoice)
{
    if (activeUserChoice->getBigPortion())
    {
        setTitle("Your choice is big portion");
    }
    else
    {
        setTitle("Your choice is regular portion");
    }

    if (activeUserChoice->getSelectedDrink() != NO_DRINK)
    {
        setDrinkName(activeUserChoice->printSelectedDrink());
    }
    else
    {
        setDrinkName("No drink selected");
    }

    setPrice(activeUserChoice->getPrice());

}
