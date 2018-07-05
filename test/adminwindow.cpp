// Created by Oleksandra Baga
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "drinkwindow.h"
#include "person.h"
#include "bankaccount.h"
#include "account.h"
#include "card.h"
#include "database.h"
#include <QtDebug>
#include <string>
#include "admin.h"

Admin *admin = NULL;
Person *adminPerson;
Person *newPerson;
BankAccount *newBankAccount;
Account *newAccount;
Card *newCard;

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("Admin Window");

    // The Person will be selected via Drop List on Main Window
    // this version work with predifined Admin Person
    adminPerson = activePerson;

    // creating the Admin Unit
    admin = new Admin(adminPerson);
    ui->labelAdminName->setText(admin->getName().c_str());

    ui->widgetAddNewEmployee->hide();

    setAdminControlButtonsStyle();

    // Loading Data Arrays: Person, Bank Account, Account, Card
    loadPersonTableWidget();
    loadBankAccountTableWidget();
    loadAccountTableWidget();
    loadCardTableWidget();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::loadPersonTableWidget()
{
    const QStringList labelsPerson = {"PersonID", "Name", "Surname", "Address", "isEmployed", "isAdmin", "isStaff"};

    // Person UI Table
    ui->tableWidgetPerson->setRowCount(Person::AllEmployee.size());
    ui->tableWidgetPerson->setColumnCount(7);
    ui->tableWidgetPerson->setHorizontalHeaderLabels(labelsPerson);

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
    const QStringList labelsBankAccount = {"Name", "Surname", "IBAN", "AccountID", "Tax Class"};

    // Bank Account Table
    ui->tableWidgetBankAccount->setRowCount(BankAccount::AllBankAccounts.size());
    ui->tableWidgetBankAccount->setColumnCount(5);
    ui->tableWidgetBankAccount->setHorizontalHeaderLabels(labelsBankAccount);
    ui->tableWidgetBankAccount->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
    const QStringList labelsAccount = {"Name", "Surname", "AccountID", "Credit", "State"};

    // Account Table
    ui->tableWidgetAccount->setRowCount(Account::AllAccounts.size());
    ui->tableWidgetAccount->setColumnCount(5);
    ui->tableWidgetAccount->setHorizontalHeaderLabels(labelsAccount);
    ui->tableWidgetAccount->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
    const QStringList labelsCard = {"Name", "Surname", "CardID", "Card Status"};

    // Card Table
    ui->tableWidgetCard->setRowCount(Card::AllCards.size());
    ui->tableWidgetCard->setColumnCount(4);
    ui->tableWidgetCard->setHorizontalHeaderLabels(labelsCard);
    ui->tableWidgetCard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Items
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


void AdminWindow::setAdminControlButtonsStyle()
{

    // Admin buttons preset
    QString colorAddNewEmployee  = QString("background-color: #0059b3; color: #ffffff;");
    ui->buttonAddNewEmployee->setStyleSheet(colorAddNewEmployee);

    QString colorEditEmployee  = QString("background-color: #0066cc; color: #ffffff;");
    ui->buttonEditEmployee->setStyleSheet(colorEditEmployee);

    QString colorEditDrinks  = QString("background-color: #0073e6; color: #ffffff;");
    ui->buttonViewDrinksRecipe->setStyleSheet(colorEditDrinks);

    QString colorIngredientStatus  = QString("background-color: #0080ff; color: #ffffff;");
    ui->buttonIngredientStatus->setStyleSheet(colorIngredientStatus);

    QString colorReloadTable  = QString("background-color: #ff6600; color: #ffffff;");
    ui->buttonReloadPersonTable->setStyleSheet(colorReloadTable);
    ui->buttonReloadBankAccountTable->setStyleSheet(colorReloadTable);
    ui->buttonReloadAccountTable->setStyleSheet(colorReloadTable);
    ui->buttonReloadCardTable->setStyleSheet(colorReloadTable);
}


void AdminWindow::on_buttonSaveNewPerson_clicked()
{
    std::string newPersonName = ui->lineNameForm->text().toUtf8().constData();

    std::string newPersonSurname = ui->lineSurnameForm->text().toUtf8().constData();

    std::string newPersonAddress = ui->lineAddressForm->text().toUtf8().constData();

    int isAdmin = (ui->comboBoxAdmin->currentIndex() == 0);

    int isStaff = (ui->comboBoxStaff->currentIndex() == 0);

    admin->addPerson(newPerson, newPersonName, newPersonSurname, newPersonAddress, isAdmin, isStaff);

    //========================================================

    admin->addAccount(newAccount);

    //========================================================

    int taxClass = ui->comboBoxTaxClass->currentIndex() + 1;

    admin->addBankAccount(newBankAccount, taxClass);

    //========================================================

    admin->addCard(newCard);

    //=======================================================
    // Free allocated memory
    //admin->clearTemporaryPointers(newPerson, newBankAccount, newAccount, newCard);
    delete newPerson;
    newPerson = NULL;

    delete newBankAccount;
    newBankAccount = NULL;

    delete newAccount;
    newAccount = NULL;

    delete newCard;
    newCard = NULL;

}

void AdminWindow::on_buttonSaveNewPerson_pressed()
{
    QString colorSaveNewPerson  = QString("background-color: #4d6600; color: #ffffff;");
    ui->buttonSaveNewPerson->setStyleSheet(colorSaveNewPerson);
}

void AdminWindow::on_buttonSaveNewPerson_released()
{
    QString colorSaveNewPerson  = QString("background-color: #739900; color: #ffffff;");
    ui->buttonSaveNewPerson->setStyleSheet(colorSaveNewPerson);
    ui->widgetAddNewEmployee->hide();
}

void AdminWindow::on_buttonAddNewEmployee_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

    newPerson = new Person();
    newBankAccount = new BankAccount();
    newCard = new Card();
    newAccount = new Account();

    ui->widgetAddNewEmployee->show();
    QString colorSaveNewPerson  = QString("background-color: #739900; color: #ffffff;");
    ui->buttonSaveNewPerson->setStyleSheet(colorSaveNewPerson);
    QString colorCancelNewPerson  = QString("background-color: #e6e6e6; color: #000000;");
    ui->buttonCancelNewPerson->setStyleSheet(colorCancelNewPerson);

    ui->labelPersonIDForm->setText(newPerson->getID().toQstring());
    ui->labelAccountIDForm->setText(newAccount->getAccountID().toQstring());
    ui->labelCardIDForm->setText(newCard->getCardID().toQstring());
}

void AdminWindow::on_buttonEditEmployee_clicked()
{
    ui->widgetAddNewEmployee->hide();
}

void AdminWindow::on_buttonViewDrinksRecipe_clicked()
{
    ui->widgetAddNewEmployee->hide();
    DrinkWindow drinkWindow;
    drinkWindow.setModal(true);
    drinkWindow.exec();
}


void AdminWindow::on_buttonIngredientStatus_clicked()
{
    ui->widgetAddNewEmployee->hide();

}


void AdminWindow::on_buttonCancelNewPerson_clicked()
{
    admin->cancelPersonCreation(newPerson);
    admin->cancelBankAccountCreation(newBankAccount);
    admin->cancelAccountCreation(newAccount);
    admin->cancelCardCreation(newCard);
    ui->widgetAddNewEmployee->hide();
}

void AdminWindow::on_buttonCancelNewPerson_pressed()
{
    QString colorCancelNewPerson  = QString("background-color: #cccccc; color: #000000;");
    ui->buttonCancelNewPerson->setStyleSheet(colorCancelNewPerson);
}

void AdminWindow::on_buttonCancelNewPerson_released()
{
    QString colorCancelNewPerson  = QString("background-color: #e6e6e6; color: #000000;");
    ui->buttonCancelNewPerson->setStyleSheet(colorCancelNewPerson);
}



