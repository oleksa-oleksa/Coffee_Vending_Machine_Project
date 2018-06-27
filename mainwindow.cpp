#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "person.h"
#include "rfid_scanner.h"

#include <QtDebug>

Person *activePerson = NULL;
Card *card = NULL;
Account *activeAccount = NULL;
RFID_Scanner RFID_s;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Coffee Machine Drinks Window");

    // select active Person
    activeAccount = &Account::AllAccounts[0];

    activePerson = activeAccount->getOwner();
    // get linked Card




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
    //Main Window buttons preset
    QString colorAdmin  = QString("background-color: #0059b3; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorAdmin);

    ui->buttonService->setStyleSheet(colorAdmin);

    QString colorCard = QString("background-color: #669900; color: #ffffff;");
    ui->buttonCard->setStyleSheet(colorCard);

}

void MainWindow::on_buttonAdmin_pressed()
{
    QString colorAdmin  = QString("background-color: #004080; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorAdmin);
}



void MainWindow::on_buttonAdmin_released()
{
    QString colorAdmin  = QString("background-color: #0059b3; color: #ffffff;");
    ui->buttonAdmin->setStyleSheet(colorAdmin);
}


void MainWindow::on_buttonCard_clicked()
{

    if (ui->labelCard->isHidden())
    {
        ui->labelCard->show();
        RFID_s.getRfidValidation(card);

    }

    else
    {
        ui->labelCard->hide();
    }
}
