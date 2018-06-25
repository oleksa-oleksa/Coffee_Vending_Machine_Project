#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "person.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_buttonPersonTable_clicked()
{

}

void AdminWindow::on_buttonBankAccountTable_clicked()
{

}

void AdminWindow::on_buttonAccountTable_clicked()
{

}

void AdminWindow::on_buttonCardTable_clicked()
{

}
