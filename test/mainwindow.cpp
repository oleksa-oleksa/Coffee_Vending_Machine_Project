#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
