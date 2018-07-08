#include "lcd_display.h"
#include "controlunit.h"
#include <QDebug>

LCD_Display::LCD_Display() {
    //actuator_duration
    actuatorType = LCD;
    actuatorState = UNDEFINED;
    isBacklit = false;
}

LCD_Display::~LCD_Display() {

}


QString LCD_Display::getTitle() const {
    return title;
}

void LCD_Display::setTitle(QString title) {
    this->title = title;
    qDebug() << "LCD: " << title;
}

QString LCD_Display::getDrinkName() const {
    return drinkName;
}

void LCD_Display::setDrinkName(QString drinkName) {
    this->drinkName = drinkName;
    qDebug() << "LCD: You have selected: " <<  this->drinkName;

}

double LCD_Display::getPrice() const {
    return price;
}

void LCD_Display::setPrice(double price) {
    this->price = price;
    qDebug() << "LCD: You have to pay " << price << "for your drink!";
}


void LCD_Display::setBacklight(bool isBacklit) {
    this->isBacklit = isBacklit;
}

bool LCD_Display::getBacklight() const {
    return isBacklit;
}

void LCD_Display::writeDefaultText(UserChoice *activeUserChoice) {
    setTitle("Please insert card");
    if (activeUserChoice->getSelectedDrink() == NO_DRINK) {
        setDrinkName("NO_DRINK");
        setPrice(0.0);
    }
    else {
        setDrinkName(activeUserChoice->printSelectedDrink());
        setPrice(activeUserChoice->getPrice());
    }

}

void LCD_Display::writeGreetingText(UserChoice *activeUserChoice) {
    QString str = activeUserChoice->getCard()->getAccount()->getOwner()->getName().c_str();
    setTitle("Nice to see you again, " + str);
    setDrinkName("Nothing");
    setPrice(activeUserChoice->getPrice());

}

void LCD_Display::writeCardErrorText() {
    setTitle("Not a valid card! Aborted...");
    setDrinkName("NO_DRINK");
    setPrice(0.0);
}

void LCD_Display::writeUserChoiceText(UserChoice *activeUserChoice) {
    if (activeUserChoice->getBigPortion()) {
        setTitle("Your choice is big portion");
    }
    else {
        setTitle("Your choice is regular portion");
    }

    if (activeUserChoice->getSelectedDrink() != NO_DRINK) {
        setDrinkName(activeUserChoice->printSelectedDrink());
    }
    else {
        setDrinkName("No drink selected");
    }

    setPrice(activeUserChoice->getPrice());

}

void LCD_Display::writeSystemErrorMessage(PreparationStatus message) {
    switch (message) {
    case (PREPARE_ERROR_NO_CARD):
        setTitle("Insert card!");
        break;
    case (PREPARE_ERROR_NO_DRINK):
        setTitle("Select drink first!");
        break;
    case (PREPARE_ERROR_NO_CUP):
        setTitle("Place cup first!");
        break;
    case (PREPARE_ERROR_FULL_CUP):
        setTitle("Take your drink first!");
        break;
    case (PREPARE_ERROR_PAYMENT):
        setTitle("Payment error! Take your card...");
        break;
    case (PREPARE_ERROR_NO_INGREDIENT):
        setTitle("Not enough ingredients!");
        break;
    case (PREPARE_ERROR_FLOW):
        setTitle("Flowmeter error. Take your card...");
        break;
    case (PREPARE_ERROR_HEATER):
        setTitle("Water heater error. Take your card...");
        break;
    default:
        break;
    }
}

void LCD_Display::writeTakeDrinkMessage() {
    setTitle("Take your drink! Don't forget your card.");
}

void LCD_Display::writeWaitText() {
    setTitle("Brewing. Please wait...");
}
