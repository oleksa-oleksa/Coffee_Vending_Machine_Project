#include "lcdtest.h"

void LcdTest::testWriteDefaultText() {

    UserChoice userChoice;
    userChoice.setSelectedDrink(NO_DRINK);

    //Test for NO_Drink
    LCD_Display lcd;
    lcd.writeDefaultText(&userChoice);
    QCOMPARE(lcd.getDrinkName(), "NO_DRINK");
    QCOMPARE(lcd.getPrice(), 0.0);

    //Test for Coffee
    userChoice.setSelectedDrink(COFFEE);
    lcd.writeDefaultText(&userChoice);
    QCOMPARE(lcd.getDrinkName(), "COFFEE");
    QCOMPARE(lcd.getPrice(), 0.9);

    //Test for a Big Drink
    userChoice.setSelectedDrink(CACAO);
    userChoice.setEnabledBigPortion();
    lcd.writeDefaultText(&userChoice);
    QCOMPARE(lcd.getDrinkName(), "CACAO");
    QCOMPARE(lcd.getPrice(), 1.60);

    //Test for a Big HotWater
    userChoice.setSelectedDrink(HOTWATER);
    userChoice.setEnabledBigPortion();
    lcd.writeDefaultText(&userChoice);
    QCOMPARE(lcd.getDrinkName(), "HOTWATER");
    QCOMPARE(lcd.getPrice(), 0.2);

}

void LcdTest::testWriteGreetingText() {

    Account ts_acc01;
    Person ts_per01;
    ts_per01.setName("Brice");

    Card test01;
    test01.setAccount(&ts_acc01);
    test01.getAccount()->setOwner(&ts_per01);

    UserChoice user;
    user.setCard(&test01);

    LCD_Display lcd;
    lcd.writeGreetingText(&user);

    QCOMPARE(lcd.getTitle(), "Nice to see you again, Brice");
    QCOMPARE(lcd.getPrice(), 0.0);
    QCOMPARE(lcd.getDrinkName(), "Nothing");

}

void LcdTest::testWriteUserChoiceText() {

    UserChoice userChoice;
    LCD_Display lcd;

    //Test for NO_Drink
    userChoice.setSelectedDrink(NO_DRINK);
    lcd.writeUserChoiceText(&userChoice);
    QCOMPARE(lcd.getTitle(), "Your choice is regular portion");
    QCOMPARE(lcd.getDrinkName(), "No drink selected");
    QCOMPARE(lcd.getPrice(), 0.0);

    //Test for a Big Drink
    userChoice.setSelectedDrink(CACAO);
    userChoice.setEnabledBigPortion();
    lcd.writeUserChoiceText(&userChoice);
    QCOMPARE(lcd.getTitle(), "Your choice is big portion");
    QCOMPARE(lcd.getDrinkName(), "CACAO");
    QCOMPARE(lcd.getPrice(), 1.60);
    userChoice.setDisabledBigPortion();

    //Test for regulat drink
    userChoice.setSelectedDrink(COFFEE);
    lcd.writeUserChoiceText(&userChoice);
    QCOMPARE(lcd.getTitle(), "Your choice is regular portion");
    QCOMPARE(lcd.getDrinkName(), "COFFEE");
    QCOMPARE(lcd.getPrice(), 0.9);

}

void LcdTest::testSystemErrorMessage() {

    LCD_Display lcd;

    lcd.writeSystemErrorMessage(PREPARE_ERROR_NO_CARD);
    QCOMPARE(lcd.getTitle(), "Insert card!");

    lcd.writeSystemErrorMessage(PREPARE_ERROR_NO_DRINK);
    QCOMPARE(lcd.getTitle(), "Select drink first!");

    lcd.writeSystemErrorMessage(PREPARE_ERROR_NO_CUP);
    QCOMPARE(lcd.getTitle(), "Place cup first!");

}


















