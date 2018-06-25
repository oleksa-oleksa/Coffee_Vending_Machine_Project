// Created by Oleksandra Baga
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "person.h"
#include "bankaccount.h"
#include "account.h"
#include "card.h"
#include "database.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    const QStringList labelsPerson = {"PersonID", "Name", "Surname", "Address", "isEmployed", "isAdmin", "isStaff"};
    const QStringList labelsBankAccount = {"Name", "Surname", "IBAN", "AccountID", "Tax Class"};
    const QStringList labelsAccount = {"Name", "Surname", "AccountID", "Credit", "State"};
    const QStringList labelsCard = {"Name", "Surname", "CardID", "Card Status"};

    // Person UI Table
    ui->tableWidgetPerson->setRowCount(Person::AllEmployee.size());
    ui->tableWidgetPerson->setColumnCount(7);
    ui->tableWidgetPerson->setHorizontalHeaderLabels(labelsPerson);

    loadPersonTableWidget();

    //============================================================================
    // Bank Account Table
    ui->tableWidgetBankAccount->setRowCount(BankAccount::AllBankAccounts.size());
    ui->tableWidgetBankAccount->setColumnCount(5);
    ui->tableWidgetBankAccount->setHorizontalHeaderLabels(labelsBankAccount);
    ui->tableWidgetBankAccount->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    loadBankAccountTableWidget();

    //============================================================================
    // Account Table
    ui->tableWidgetAccount->setRowCount(Account::AllAccounts.size());
    ui->tableWidgetAccount->setColumnCount(5);
    ui->tableWidgetAccount->setHorizontalHeaderLabels(labelsAccount);
    ui->tableWidgetAccount->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    loadAccountTableWidget();

    //============================================================================
    // Card Table

    ui->tableWidgetCard->setRowCount(Card::AllCards.size());
    ui->tableWidgetCard->setColumnCount(4);
    ui->tableWidgetCard->setHorizontalHeaderLabels(labelsCard);
    ui->tableWidgetCard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    loadCardTableWidget();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::loadPersonTableWidget()
{
     // Items
    for (size_t row = 0; row < Person::AllEmployee.size(); row++)
    {
        ui->tableWidgetPerson->setItem(row, 0, new QTableWidgetItem(Person::AllEmployee[row].getID().toQstring()));
        ui->tableWidgetPerson->setItem(row, 1, new QTableWidgetItem(Person::AllEmployee[row].getName().c_str()));
        ui->tableWidgetPerson->setItem(row, 2, new QTableWidgetItem(Person::AllEmployee[row].getSurname().c_str()));
        ui->tableWidgetPerson->setItem(row, 3, new QTableWidgetItem(Person::AllEmployee[row].getAddress().c_str()));
        ui->tableWidgetPerson->setItem(row, 4, new QTableWidgetItem(Person::AllEmployee[row].getEmployed() ? "true" : "false"));
        ui->tableWidgetPerson->setItem(row, 5, new QTableWidgetItem(Person::AllEmployee[row].getAdmin() ? "true" : "false"));
        ui->tableWidgetPerson->setItem(row, 6, new QTableWidgetItem(Person::AllEmployee[row].getStaff() ? "true" : "false"));
    }
}

void AdminWindow::loadBankAccountTableWidget()
{
    // Items
    for (size_t row = 0; row < BankAccount::AllBankAccounts.size(); row++)
    {
        ui->tableWidgetBankAccount->setItem(row, 0, new QTableWidgetItem(Person::AllEmployee[row].getName().c_str()));
        ui->tableWidgetBankAccount->setItem(row, 1, new QTableWidgetItem(Person::AllEmployee[row].getSurname().c_str()));
        ui->tableWidgetBankAccount->setItem(row, 2, new QTableWidgetItem(BankAccount::AllBankAccounts[row].getIBAN().toQstring()));
        ui->tableWidgetBankAccount->setItem(row, 3, new QTableWidgetItem(BankAccount::AllBankAccounts[row].getAccountID().toQstring()));
        ui->tableWidgetBankAccount->setItem(row, 4, new QTableWidgetItem(QString::number(BankAccount::AllBankAccounts[row].getTaxClass())));
    }
}

void AdminWindow::loadAccountTableWidget()
{
    // Items
    for (size_t row = 0; row < Account::AllAccounts.size(); row++)
    {
        ui->tableWidgetAccount->setItem(row, 0, new QTableWidgetItem(Person::AllEmployee[row].getName().c_str()));
        ui->tableWidgetAccount->setItem(row, 1, new QTableWidgetItem(Person::AllEmployee[row].getSurname().c_str()));
        ui->tableWidgetAccount->setItem(row, 2, new QTableWidgetItem(Account::AllAccounts[row].getAccountID().toQstring()));
        ui->tableWidgetAccount->setItem(row, 3, new QTableWidgetItem(QString::number(Account::AllAccounts[row].getAccountCredit())));
        ui->tableWidgetAccount->setItem(row, 4, new QTableWidgetItem(Account::AllAccounts[row].printAccountStatus()));
    }
}

void AdminWindow::loadCardTableWidget()
{
    for (size_t row = 0; row < Account::AllAccounts.size(); row++)
    {
        ui->tableWidgetCard->setItem(row, 0, new QTableWidgetItem(Person::AllEmployee[row].getName().c_str()));
        ui->tableWidgetCard->setItem(row, 1, new QTableWidgetItem(Person::AllEmployee[row].getSurname().c_str()));
        ui->tableWidgetCard->setItem(row, 2, new QTableWidgetItem(Card::AllCards[row].getCardID().toQstring()));
        ui->tableWidgetCard->setItem(row, 3, new QTableWidgetItem(Card::AllCards[row].printCardStatus()));
    }
}

void AdminWindow::on_buttonReloadPersonTable_clicked()
{
    loadPersonTableWidget();
}

void AdminWindow::on_buttonReloadBankAccountTable_clicked()
{
    loadBankAccountTableWidget();
}

void AdminWindow::on_buttonReloadAccountTable_clicked()
{
    loadAccountTableWidget();
}

void AdminWindow::on_buttonReloadCardTable_clicked()
{
    loadCardTableWidget();
}
