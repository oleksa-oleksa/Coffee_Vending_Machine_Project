// Created by Oleksandra Baga
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "person.h"
#include "bankaccount.h"
#include "account.h"
#include "card.h"
#include "database.h"
#include <QtDebug>
#include <string>

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("Admin Window");

    activeAdmin = &Person::AllEmployee[0];
    ui->labelAdminName->setText(activeAdmin->getName().c_str());

    ui->widgetAddNewEmployee->hide();

    setAdminControlButtonsStyle();

    // Loading Data Arrays: Person, Bank Account, Account, Card
    newPerson = NULL;
    newBankAccount = NULL;
    newAccount = NULL;
    newCard = NULL;
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
    ui->buttonEditDrinks->setStyleSheet(colorEditDrinks);

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
    newPerson->setName(newPersonName);

    std::string newPersonSurname = ui->lineSurnameForm->text().toUtf8().constData();
    newPerson->setSurname(newPersonSurname);

    std::string newPersonAddress = ui->lineAddressForm->text().toUtf8().constData();
    newPerson->setAddress(newPersonAddress);

    newPerson->setEmployed(true);

    int isAdmin = (ui->comboBoxAdmin->currentIndex() == 0);
    newPerson->setAdmin(isAdmin);

    int isStaff = (ui->comboBoxStaff->currentIndex() == 0);
    newPerson->setStaff(isStaff);

    Person::AllEmployee.push_back(*newPerson);
    delete newPerson; newPerson = NULL;

    qDebug() << "New Person added into AllEmployee";

    //=====================================================================

    newBankAccount->setAccountID(newAccount->getAccountID());

    int taxClass = ui->comboBoxTaxClass->currentIndex() + 1;
    newBankAccount->setTaxClass(taxClass);
    BankAccount::AllBankAccounts.push_back(*newBankAccount);

    delete newBankAccount; newBankAccount = NULL;
    BankAccount &lastBankAccount = BankAccount::AllBankAccounts.back();

    qDebug() << "New depending Bank Account added into AllBankAccounts";

    //=====================================================================
    // Account accountID, credit and state are predefined by constructor

    // newAccount->setOwner(newPerson);
    // newAccount->setBankAccount(newBankAccount);

    Account::AllAccounts.push_back(*newAccount);
    Account &lastAccount = Account::AllAccounts.back();
    delete newAccount; newAccount = NULL;

    lastAccount.setBankAccount(&lastBankAccount);
    lastBankAccount.setAccount(&Account::AllAccounts.back());
    qDebug() << "New depending Account added into AllAccounts";

    //=====================================================================
    // CardID and CardStatus are predefined by constructor

    Card::AllCards.push_back(*newCard);
    Card::AllCards.back().setAccount(&lastAccount);
    delete newCard; newCard = NULL;
    qDebug() << "New depending Card added into AllAccounts";
}

void AdminWindow::instantiateNewObjects()
{
    if (!newPerson)
        newPerson = new Person();

    if (!newBankAccount)
        newBankAccount = new BankAccount();

    if (!newAccount)
        newAccount = new Account();

    if (!newCard)
        newCard = new Card();
}

void AdminWindow::on_buttonAddNewEmployee_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

    instantiateNewObjects();

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

void AdminWindow::on_buttonEditDrinks_clicked()
{
    ui->widgetAddNewEmployee->hide();
}

void AdminWindow::on_buttonIngredientStatus_clicked()
{
    ui->widgetAddNewEmployee->hide();

}


void AdminWindow::on_buttonCancelNewPerson_clicked()
{
    ui->widgetAddNewEmployee->hide();
    delete newCard; newCard = NULL;
    delete newAccount; newAccount = NULL;
    delete newBankAccount; newBankAccount = NULL;
    delete newPerson; newPerson = NULL;

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
