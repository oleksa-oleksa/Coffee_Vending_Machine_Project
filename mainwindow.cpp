#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Coffee Machine Drinks Window");

    setMainWindowControlButtonsStyle();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_coffeeButton_clicked()
{

}

void MainWindow::on_cappuccinoButton_clicked()
{

}

void MainWindow::on_espressoButton_clicked()
{

}

void MainWindow::on_cacaoButton_clicked()
{

}

void MainWindow::on_latteMacchiatoButton_clicked()
{

}

void MainWindow::on_hotWaterButton_clicked()
{

}

void MainWindow::on_decreaseMilk_clicked()
{

}

void MainWindow::on_addMilk_clicked()
{

}

void MainWindow::on_decreaseSugar_clicked()
{

}

void MainWindow::on_addSugar_clicked()
{

}

void MainWindow::on_buttonStart_clicked()
{

}

void MainWindow::on_buttonService_clicked()
{
    static int isDown = 1;

    if ( isDown )
    {
        isDown--;
        qDebug() << "Service Button is down";
    }
    else
    {
        isDown++;
        qDebug() << "Service Button is up";
    }
}

void MainWindow::on_buttonBigCup_clicked()
{
    static int isDown = 1;

    if ( isDown )
    {
        isDown--;
        qDebug() << "BigCup Button is down";
    }
    else
    {
        isDown++;
        qDebug() << "BigCup Button is up";
    }
}

void MainWindow::on_buttonPlaceCard_clicked()
{
    static int isDown = 1;

    if ( isDown )
    {
        isDown--;
        qDebug() << "Place Card Button is down";
    }
    else
    {
        isDown++;
        qDebug() << "Place Card Button is up";
    }
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

