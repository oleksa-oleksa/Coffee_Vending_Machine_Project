// Created by Oleksandra Baga
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "person.h"
#include "rfid_scanner.h"
#include "QTimer"
#include <QtDebug>
#include "interactionunit.h"
#include "userchoice.h"
#include "button.h"
#include "lcd_display.h"

Person *activePerson = NULL;
Card *card = NULL;
Account *activeAccount = NULL;
BankAccount *bankAccount = NULL;
InteractionUnit iunit;
UserChoice *activeUserChoice = NULL;

Button moreSugar;
Button lessSugar;
Button moreMilk;
Button lessMilk;
Button coffee;
Button cappuccino;
Button espresso;
Button latteMacchiato;
Button cacao;
Button hotWater;
Button bigPortion;
Button cancel;
Button start;

RFID_Scanner RFID_s;
LCD_Display display;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Coffee Machine Drinks Window");

    // MODEL
    // Creating dependencies for simulation
    // there is always an active person interacting with Vending Machine
    // To change the game characher the drop list should be used
    // and new charachter will be loaded with button "load"

    // Firstly, we will start with a card provided by user into RFID
    card = &Card::AllCards[0];

    // Thus we can find out which account belongs to the card
    activeAccount = card->getAccount();

    // and what the person interacts with Vending Machine
    activePerson = card->getAccount()->getOwner();

    // and which bank account is connected to the card for withdrawing process
    bankAccount = card->getAccount()->getBankAccount();

    // Note: to simulate invalid card
    // 1: Comment all card, ba, acc and person lins
    // 2. create a new random Card *card
    // 3. run programm

    //======================================================================
    // and finaly: UserChoice initialisation in InteractionUnit in order
    // to track all interactions with buttons
    // This solution based on UML Diagramm created for the University Course
    iunit.setMoreSugar(&moreSugar);
    iunit.setLessSugar(&lessSugar);
    iunit.setMoreMilk(&moreMilk);
    iunit.setLessMilk(&lessMilk);
    iunit.setCoffee(&coffee);
    iunit.setCappuccino(&cappuccino);
    iunit.setEspresso(&espresso);
    iunit.setLatteMacchiato(&latteMacchiato);
    iunit.setCacao(&cacao);
    iunit.setHotWater(&hotWater);
    iunit.setBigPortion(&bigPortion);
    iunit.setCancel(&cancel);
    iunit.setStart(&start);

    // activeUserChoice has the selected drink with  price and recipe
    // the information for preparation will be transfered to ControlUnit with "Start" button
    activeUserChoice = iunit.initUserChoice(card);

    // block the possibility to change drinks settins
    // without a valid card inside
    RFID_s.getIsCardInside();

    // Now we can design the Main Window

    // MODEL
    display.writeDefaultText(activeUserChoice);

    // VIEW
    restartLCD();
    setMainWindowControlButtonsStyle();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonAdmin_clicked()
{
    // Modal approach to show a second window
    // It is impossible to access the first window during the session in the second window
    AdminWindow adminWindow;
    adminWindow.setModal(true);
    adminWindow.exec();
}


void MainWindow::setMainWindowControlButtonsStyle()
{
    ui->labelCard->hide();
    styleInsertButton();

    //Main Window buttons preset
    QString colorTopButtons  = QString("background-color: #4d2600; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorTopButtons);
    ui->buttonService->setStyleSheet(colorTopButtons);

    ui->buttonBigPortion->setCheckable(true);
    ui->buttonBigPortion->setChecked(false);

    QString colorDrinks = QString("background-color: #663300; color: #ffffff;");
    ui->buttonLessSugar->setStyleSheet(colorDrinks);
    ui->buttonMoreSugar->setStyleSheet(colorDrinks);
    ui->buttonLessMilk->setStyleSheet(colorDrinks);
    ui->buttonMoreMilk->setStyleSheet(colorDrinks);

    disableControlButtons();

    ui->progressBarSugar->setStyleSheet("QProgressBar::chunk {background-color: #a58a73; width: 3px; margin: 1px;}");
    ui->progressBarSugar->setTextVisible(false);
    styleSugarProgressBar();

    ui->progressBarMilk->setStyleSheet("QProgressBar::chunk {background-color: #a58a73; width: 3px; margin: 1px;}");
    ui->progressBarMilk->setTextVisible(false);
    styleMilkProgressBar();

    styleDrinkButtons();

}

void MainWindow::on_buttonCard_clicked()
{
    // if NO card in RFID
    if (!RFID_s.getIsCardInside())
    {
        ui->labelCard->show();

        // if card is valid, user can purchase a drink
        // here starts the main interaction with GUI after card validation

        // After card was inserted, the RFID Scanner provides verification
        // without instructions outside
        // modifies private attribute isChoiceAllowed for InteractionUnit
        if (RFID_s.insertCard(card))
        {
            // MODEL
            display.writeGreetingText(activeUserChoice);

            // VIEW
            styleLCDGreeting();
            styleSugarProgressBar();
            styleMilkProgressBar();
            styleEjectButton();
        }

        // if card is not valid, it will ba automaticaly ejected (simulation in Design)
        // and the purschasing will be ended
        // the next card can be inserted in RFID
        else
        {
            // MODEL
            display.writeErrorText();
            RFID_s.ejectCard();

            // VIEW
            styleLCDErrorCard();
            QTimer::singleShot(3000, this, &MainWindow::restartLCDCardEjected);
            ui->labelCard->hide();
            styleInsertButton();
            disableControlButtons();
        }
    }

    // if there IS A CARD
    else
    {
        // MODEL
        RFID_s.ejectCard();
        delete(activeUserChoice);
        activeUserChoice = iunit.initUserChoice(card);
        display.writeDefaultText(activeUserChoice);

        // VIEW
        ui->labelCard->hide();
        restartLCD();
        styleInsertButton();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleDrinkButtons();
        disableControlButtons();
        ui->buttonBigPortion->setChecked(false);
    }
}

void MainWindow::restartLCD()
{
    // VIEW
    ui->labelLCD->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->setText(display.getTitle());
    ui->labelSelectedDrink->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelPrice->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelSelectedDrink->setText("");
    ui->labelPrice->setText("");



}

void MainWindow::restartLCDCardEjected()
{
    // MODEL
    display.writeDefaultText(activeUserChoice);

    // VIEW
    ui->labelLCD->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->setText("Please insert card");
    ui->labelLCD->show();

    ui->labelSelectedDrink->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelPrice->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->show();

    styleSugarProgressBar();
    styleMilkProgressBar();



}

void MainWindow::on_buttonLessSugar_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        lessSugar.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        lessSugar.setSensorState(RELEASED);

        styleSugarProgressBar();
    }
}

void MainWindow::on_buttonMoreSugar_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        moreSugar.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        moreSugar.setSensorState(RELEASED);

        styleSugarProgressBar();
    }
}

void MainWindow::on_buttonLessMilk_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        lessMilk.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        lessMilk.setSensorState(RELEASED);

        styleMilkProgressBar();
    }
}

void MainWindow::on_buttonMoreMilk_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        moreMilk.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        moreMilk.setSensorState(RELEASED);

        styleMilkProgressBar();
    }
}


void MainWindow::styleMilkProgressBar()
{
   if (RFID_s.isValidCardInside())
    {
        ui->progressBarMilk->setValue(activeUserChoice->getMilkAmount());
        QString num = QString::number(activeUserChoice->getMilkAmount());
        ui->labelMilkAmount->setText(num);
    }
   else
   {
       ui->progressBarMilk->setValue(0);
       ui->labelMilkAmount->setText(0);
   }
}

void MainWindow::styleSugarProgressBar()
{
    if (RFID_s.isValidCardInside())
    {
        ui->progressBarSugar->setValue(activeUserChoice->getSugarAmount());
        QString num = QString::number(activeUserChoice->getSugarAmount());
        ui->labelSugarAmount->setText(num);
    }
    else {
        ui->progressBarSugar->setValue(0);
        ui->labelSugarAmount->setText(0);
    }
}

void MainWindow::styleLCDChoiceInformation()
{
    ui->labelLCD->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->setText("Your choice:");

    ui->labelSelectedDrink->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelSelectedDrink->setText(display.getDrinkName());

    QString num = QString::number(activeUserChoice->getPrice(), 'f', 2);
    ui->labelPrice->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelPrice->setText(num);
}

void MainWindow::styleLCDGreeting()
{   
    ui->labelLCD->setStyleSheet("color: #ffb366; border: 0px;");

    if (activeUserChoice->getSelectedDrink() == NO_DRINK)
    {
        ui->labelLCD->setText(display.getTitle());
        ui->labelSelectedDrink->setText("");
        ui->labelPrice->setText("");
    }
    else
    {
        ui->labelLCD->setText(display.getTitle());
        ui->labelSelectedDrink->setText(display.getDrinkName());
        ui->labelPrice->setText(QString::number(display.getPrice()));
    }

}

void MainWindow::styleLCDErrorCard()
{
    ui->labelLCD->setStyleSheet("color: #ff1a1a; border: 0px;");

    ui->labelLCD->setText(display.getTitle());

    ui->labelSelectedDrink->setText("");
    ui->labelPrice->setText("");
}

void MainWindow::styleEjectButton()
{
    ui->buttonCard->setStyleSheet("background-color: #e67300; color: #ffffff;");
    ui->buttonCard->setText("Eject card");
}

void MainWindow::styleInsertButton()
{
    ui->buttonCard->setStyleSheet("background-color: #e67300; color: #ffffff;");
    ui->buttonCard->setText("Insert card");
}

void MainWindow::styleDrinkButtons()
{
    ui->buttonCoffee->setStyleSheet("background-color: #663300; color: #ffffff;");
    ui->buttonCappuccino->setStyleSheet("background-color: #663300; color: #ffffff;");
    ui->buttonEspresso->setStyleSheet("background-color: #663300; color: #ffffff;");
    ui->buttonLatteMacchiato->setStyleSheet("background-color: #663300; color: #ffffff;");
    ui->buttonCacao->setStyleSheet("background-color: #663300; color: #ffffff;");
    ui->buttonHotwater->setStyleSheet("background-color: #663300; color: #ffffff;");
    ui->buttonStart->setStyleSheet("background-color: #808000; color: #ffffff;");
    ui->buttonCancel->setStyleSheet("background-color: #4d0000; color: #ffffff;");
    ui->buttonBigPortion->setStyleSheet("background-color: #e67300; color: #ffffff;");

}

void MainWindow::on_buttonCoffee_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        // MODEL
        coffee.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        coffee.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonCappuccino_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        // MODEL
        cappuccino.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        cappuccino.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonEspresso_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        // MODEL
        espresso.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        espresso.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonLatteMacchiato_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        // MODEL
        latteMacchiato.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        latteMacchiato.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonCacao_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        // MODEL
        cacao.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        cacao.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonHotwater_clicked()
{
    if (RFID_s.isValidCardInside())
    {
        // MODEL
        hotWater.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        hotWater.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonBigPortion_clicked()
{
    if (RFID_s.isValidCardInside())
    {

        bigPortion.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        bigPortion.setSensorState(RELEASED);
        display.writeUserChoiceText(activeUserChoice);

        styleLCDChoiceInformation();
    }
}

void MainWindow::enableControlButtons()
{
    ui->buttonBigPortion->setEnabled(true);
    ui->buttonMoreMilk->setEnabled(true);
    ui->buttonLessMilk->setEnabled(true);
    ui->buttonMoreSugar->setEnabled(true);
    ui->buttonLessSugar->setEnabled(true);
}

void MainWindow::disableControlButtons()
{
    ui->buttonBigPortion->setEnabled(false);
    ui->buttonMoreMilk->setEnabled(false);
    ui->buttonLessMilk->setEnabled(false);
    ui->buttonMoreSugar->setEnabled(false);
    ui->buttonLessSugar->setEnabled(false);
}



void MainWindow::on_buttonCancel_clicked()
{
    // MODEL
    activeUserChoice->setDefaultChoice();
    display.writeUserChoiceText(activeUserChoice);

    // VIEW
    disableControlButtons();
    styleMilkProgressBar();
    styleSugarProgressBar();
    styleLCDChoiceInformation();
}


void MainWindow::on_buttonStart_clicked()
{
    // first sensor
}
