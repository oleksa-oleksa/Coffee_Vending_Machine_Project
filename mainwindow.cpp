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

    QString colorService = QString("background-color: #993366; color: #ffffff;");
    ui->buttonService->setStyleSheet(colorService);

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

