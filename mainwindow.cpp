// Created by Oleksandra Baga
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "person.h"
#include "rfid_scanner.h"
#include <QTimer>
#include <QtDebug>
#include "interactionunit.h"
#include "userchoice.h"
#include "button.h"
#include "lcd_display.h"
#include "opticalsensor.h"
#include "flowmeter.h"
#include "controlunit.h"

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

ControlUnit control;

RFID_Scanner cardScanner;
Flowmeter flow;
OpticalSensor opticalSensor(&flow);
PressureSensor pressureSensor;
TemperaturSensor temperatureSensor;
BrightnessSensor brightSensor;

LCD_Display display;
DC_Motor motor[4];
Waterheater heater;
Milkmaker milkMaker;

Brewgroup brew;

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
    // Note: to simulate invalid card
    // 1: Comment all card, ba, acc and person lines
    // 2. create a new random Card *card
    // 3. run programm
    //Card *card;

    resetActiveEntities(&Card::AllCards[0]);
    resetServiceButtons();
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

    // links to ControlUnit
    control.linkInteractionUnit(&iunit);

    // Connect the sensors
    control.connectRFID(&cardScanner);
    control.connectFlow(&flow);
    control.connectOptical(&opticalSensor);
    control.connectPressure(&pressureSensor);
    control.connectTemperatur(&temperatureSensor);
    control.connectBrightnessSensor(&brightSensor);

    // connect the actuators
    control.connectLCD(&display);
    control.connectMotor(&motor[0], 4);
    control.connectHeater(&heater);
    control.connectMilkMaker(&milkMaker);
    control.connectBrewGroup(&brew);

    // check sensors and actuators
    control.maintenanceRoutine();
    control.onStartInit();

    // Now we can design the Main Window
    // MODEL
    control.writeMessageLCD(DEFAULT);

    // VIEW
    restartLCD();
    setMainWindowControlButtonsStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetActiveEntities(Card *c)
{

    // Firstly, we will start with a card provided by user into RFID
    card = c;

    // Thus we can find out which account belongs to the card
    activeAccount = card->getAccount();

    // and what the person interacts with Vending Machine
    activePerson = card->getAccount()->getOwner();

    // and which bank account is connected to the card for withdrawing process
    bankAccount = card->getAccount()->getBankAccount();

    if (activeUserChoice) {
        delete activeUserChoice;
    }

    activeUserChoice = iunit.initUserChoice(card);

}

void MainWindow::resetServiceButtons()
{
    if (!activePerson->getEmployed()) {
        disableServiceButtons();
        return;
    }
    ui->buttonAdmin->setEnabled(activePerson->getAdmin());
    ui->buttonService->setEnabled(activePerson->getStaff());
}

void MainWindow::disableServiceButtons()
{
    ui->buttonAdmin->setEnabled(false);
    ui->buttonService->setEnabled(false);
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
    styleCardHolder();
    styleEmptyCupHolder();

    ui->buttonRefreshUsers->setStyleSheet("background-color: #e67300; color: #ffffff;");

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
    switch (control.insertCard(card)) {
    case (VALID_CARD_INSIDE):
        ui->labelCard->show();
        ui->comboboxSelectPerson->setEnabled(false);
        styleLCDGreeting();
        styleSugarProgressBar();
        styleMilkProgressBar();
        styleEjectButton();
        break;
    case (NONVALID_CARD_INSIDE):
        ui->labelCard->show();
        ui->comboboxSelectPerson->setEnabled(true);
        control.writeMessageLCD(ERROR);
        styleLCDErrorCard();
        QTimer::singleShot(3000, this, &MainWindow::restartLCDCardEjected);
        styleInsertButton();
        disableControlButtons();
        break;
    case (NO_CARD):
        ui->comboboxSelectPerson->setEnabled(true);
        ui->labelCard->hide();
        restartLCD();
        styleInsertButton();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleDrinkButtons();
        disableControlButtons();
        ui->buttonBigPortion->setChecked(false);
        break;
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
    control.writeMessageLCD(DEFAULT);

    // VIEW
    ui->labelCard->hide();

    ui->labelLCD->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->setText(display.getTitle());
    ui->labelLCD->show();

    ui->labelSelectedDrink->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelPrice->setStyleSheet("color: #ffffff; border: 0px;");
    ui->labelLCD->show();

    styleSugarProgressBar();
    styleMilkProgressBar();



}

void MainWindow::on_buttonLessSugar_clicked()
{
    if (control.checkCard())
    {
        lessSugar.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        lessSugar.setSensorState(RELEASED);

        styleSugarProgressBar();
    }
}

void MainWindow::on_buttonMoreSugar_clicked()
{
    if (control.checkCard() && control.checkSugarAmount())
    {
        moreSugar.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        moreSugar.setSensorState(RELEASED);

        styleSugarProgressBar();
    }
}

void MainWindow::on_buttonLessMilk_clicked()
{
    if (control.checkCard())
    {
        lessMilk.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        lessMilk.setSensorState(RELEASED);

        styleMilkProgressBar();
    }
}

void MainWindow::on_buttonMoreMilk_clicked()
{
    if (control.checkCard() && control.checkMilkAmount())
    {
        moreMilk.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        moreMilk.setSensorState(RELEASED);

        styleMilkProgressBar();
    }
}


void MainWindow::styleMilkProgressBar()
{
   if (control.checkCard())
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
    if (control.checkCard())
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


void MainWindow::styleLCDErrorSystem()
{
    ui->labelLCD->setStyleSheet("color: #ff1a1a; border: 0px;");
    ui->labelLCD->setText(display.getTitle());

    ui->labelSelectedDrink->setText(display.getDrinkName());

    QString num = QString::number(activeUserChoice->getPrice(), 'f', 2);
    ui->labelPrice->setText(num);
}

void MainWindow::styleLCDWait() {
    ui->labelLCD->setStyleSheet("color: #88cc00; border: 0px;");
    ui->labelLCD->setText(display.getTitle());
}


void MainWindow::styleLCDTakeDrink() {

    ui->labelLCD->setStyleSheet("color: #88cc00; border: 0px;");
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
    if (control.checkCard())
    {
        // MODEL
        coffee.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        coffee.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonCappuccino_clicked()
{
    if (control.checkCard())
    {
        // MODEL
        cappuccino.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        cappuccino.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonEspresso_clicked()
{
    if (control.checkCard())
    {
        // MODEL
        espresso.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        espresso.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonLatteMacchiato_clicked()
{
    if (control.checkCard())
    {
        // MODEL
        latteMacchiato.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        latteMacchiato.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonCacao_clicked()
{
    if (control.checkCard())
    {
        // MODEL
        cacao.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        cacao.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonHotwater_clicked()
{
    if (control.checkCard())
    {
        // MODEL
        hotWater.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        hotWater.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

        // VIEW
        enableControlButtons();
        styleMilkProgressBar();
        styleSugarProgressBar();
        styleLCDChoiceInformation();
    }
}

void MainWindow::on_buttonBigPortion_clicked()
{
    if (control.checkCard())
    {

        bigPortion.setSensorState(PRESSED);
        iunit.buttonPollingRoutine();
        bigPortion.setSensorState(RELEASED);
        control.writeMessageLCD(USER_CHOICE);

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
    ui->buttonStart->setEnabled(true);
    ui->buttonCancel->setEnabled(true);
}

void MainWindow::disableControlButtons()
{
    ui->buttonBigPortion->setEnabled(false);
    ui->buttonMoreMilk->setEnabled(false);
    ui->buttonLessMilk->setEnabled(false);
    ui->buttonMoreSugar->setEnabled(false);
    ui->buttonLessSugar->setEnabled(false);
    ui->buttonStart->setEnabled(false);
    ui->buttonCancel->setEnabled(false);
}


void MainWindow::on_buttonCancel_clicked()
{
    // MODEL
    activeUserChoice->setDefaultChoice();
    control.writeMessageLCD(USER_CHOICE);

    // VIEW
    disableControlButtons();
    styleMilkProgressBar();
    styleSugarProgressBar();
    styleLCDChoiceInformation();
}


void MainWindow::on_buttonStart_clicked()
{
    // Either "ALLOWED" or some type of error
    PreparationStatus status = control.checkStartConditions();

    if (status == PREPARE_IS_ALLOWED) {

        control.blockCupHolder();
        styleBlockedCupHolder();

        styleLCDWait();

        // DRINK PREPARATION
        // Either "DONE" or some type of error
        if (control.prepareSelectedDrink() == PREPARE_DONE) {
             control.unblockCupHolder();
             styleCupWithDrink();
             styleLCDTakeDrink();
        }
            else {
            control.unblockCupHolder();
            styleEmptyCupHolder();
            styleLCDErrorSystem();
        }
    } else if (status == PREPARE_ERROR_FULL_CUP) {
        //qDebug() << "ERROR: Remove the drink first";
        styleLCDErrorSystem();
    }
    else {
        control.unblockCupHolder();
        styleEmptyCupHolder();
        styleLCDErrorSystem();
    }
}

void MainWindow::styleEmptyCupHolder()
{
    ui->buttonCupPlaceEmpty->show();
    ui->buttonCupPlaceEmpty->setStyleSheet("background-color: #e67300; color: #ffffff;");
    ui->buttonCupPlaceEmpty->setText("Place cup");

    ui->buttonCupTakeCupBack->hide();

    ui->buttonCupTakeDrink->hide();

    ui->labelCupEmpty->hide();
    ui->labelCupFull->hide();
}



void MainWindow::styleBlockedCupHolder()
{
    ui->buttonCupPlaceEmpty->hide();

    ui->buttonCupTakeCupBack->hide();

    ui->buttonCupTakeDrink->hide();

    ui->labelCupEmpty->show();
    ui->labelCupFull->hide();
}

void MainWindow::styleCupPlacedEmplty()
{
    ui->buttonCupPlaceEmpty->hide();

    ui->buttonCupTakeCupBack->show();
    ui->buttonCupTakeCupBack->setStyleSheet("background-color: #e67300; color: #ffffff;");
    ui->buttonCupTakeCupBack->setText("Take cup");

    ui->buttonCupTakeDrink->hide();

    ui->labelCupEmpty->show();
    ui->labelCupFull->hide();
}

void MainWindow::styleCupWithDrink()
{
    ui->buttonCupPlaceEmpty->hide();
    ui->buttonCupTakeCupBack->hide();

    ui->buttonCupTakeDrink->show();
    ui->buttonCupTakeDrink->setStyleSheet("background-color: #e67300; color: #ffffff;");
    ui->buttonCupTakeDrink->setText("Take drink");

    ui->labelCupEmpty->hide();
    ui->labelCupFull->show();

}


void MainWindow::styleCardHolder()
{

    switch (cardScanner.InitRFID()) {
    case VALID_CARD_INSIDE:
                    ui->labelCard->show();
                    styleEjectButton();
                    break;
    case NO_CARD:
                    ui->labelCard->hide();
                    styleInsertButton();
                    break;
    case NONVALID_CARD_INSIDE:
                    break;
    }
}


void MainWindow::on_buttonCupPlaceEmpty_clicked()
{
    switch (control.checkCupHolder()) {
        case NO_CUP:
                    styleCupPlacedEmplty();
                    break;
        default:
                    break;
    }
    styleLCDChoiceInformation();
}


void MainWindow::on_buttonCupTakeCupBack_clicked()
{
    switch (control.checkCupHolder()) {
        case EMPTY_CUP:
                    styleEmptyCupHolder();
                    break;
        default:
                    break;
    }
    styleLCDChoiceInformation();
}


void MainWindow::on_buttonCupTakeDrink_clicked()
{
    if (control.isBrewingFinished()) {
        styleEmptyCupHolder();
        flow.setHasPreparedDrink(false);
        opticalSensor.setDistanceToObject(10);
        ui->buttonBigPortion->setChecked(false);

    }

    styleLCDChoiceInformation();
}

void MainWindow::on_comboboxSelectPerson_currentIndexChanged(int index)
{
    if (index < 0) {
        card = NULL;
        return;
    }

    resetActiveEntities(&Card::AllCards[index]);
    resetServiceButtons();
    qDebug() << "New current active person: " <<
                QString::fromUtf8(activePerson->getSurname().c_str());
}

void MainWindow::on_buttonRefreshUsers_clicked()
{
    ui->comboboxSelectPerson->resetContent();
}

void MainWindow::on_buttonService_clicked()
{
    if (!activePerson->getStaff())
        return;

    control.staffServiceRoutine();
}
