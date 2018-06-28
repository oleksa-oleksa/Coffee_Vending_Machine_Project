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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Coffee Machine Drinks Window");

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

    // Now we can design the Main Window
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

    ui->labelLCD->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->setText("Please insert card");
    ui->labelSelectedDrink->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelPrice->setStyleSheet("color: #ffffff; border: 0px;");

    //Main Window buttons preset
    QString colorTopButtons  = QString("background-color: #4d2600; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorTopButtons);
    ui->buttonService->setStyleSheet(colorTopButtons);

    QString colorCard = QString("background-color: #669900; color: #ffffff;");
    ui->buttonCard->setStyleSheet(colorCard);

}

void MainWindow::on_buttonAdmin_pressed()
{
    QString colorTopButtons  = QString("background-color: #994d00; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorTopButtons);
}



void MainWindow::on_buttonAdmin_released()
{
    QString colorTopButtons  = QString("background-color: #4d2600; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorTopButtons);
}

void MainWindow::on_buttonService_pressed()
{
    QString colorTopButtons  = QString("background-color: #994d00; color: #ffffff;");
    ui->buttonService->setStyleSheet(colorTopButtons);
}


void MainWindow::on_buttonService_released()
{
    QString colorTopButtons  = QString("background-color: #4d2600; color: #ffffff;");
    ui->buttonService->setStyleSheet(colorTopButtons);
}


void MainWindow::on_buttonCard_clicked()
{
    bool ret;

    // if not card in RFID, card simulated
    if (ui->labelCard->isHidden())
    {
        ui->labelCard->show();
        ret = RFID_s.getRfidValidation(card);

        // if card is valid, user can purchase a drink
        // basicaly here starts the main interaction with GUI after card validation
        if (ret)
        {
            QString name = activeAccount->getOwner()->getName().c_str();
            ui->labelLCD->setStyleSheet("color: #ffa31a; border: 0px;");
            ui->labelLCD->setText("Nice to see you again " + name + "!");

        }

        // if card is not valid, it will ba automaticaly ejected (simulation)
        // and the purschasing will be ended
        // the next card can be inserted in RFID
        else
        {
            ui->labelCard->hide();
            // Design red text
            ui->labelLCD->setStyleSheet("color: #ff1a1a; border: 0px;");
            ui->labelLCD->setText("Not a valid card! Aborted...");

            QTimer::singleShot(3000, this, &MainWindow::restartLCD);
        }
    }

    else
    {
        ui->labelCard->hide();
        restartLCD();
    }
}

void MainWindow::restartLCD()
{
          ui->labelLCD->setStyleSheet("color: #ffffff; border: 0px;");
          ui->labelLCD->setText("Please insert card");
          ui->labelLCD->show();

          ui->labelSelectedDrink->setStyleSheet("color: #ffffff; border: 0px;");
          ui->labelPrice->setStyleSheet("color: #ffffff; border: 0px;");
          ui->labelLCD->show();
}
