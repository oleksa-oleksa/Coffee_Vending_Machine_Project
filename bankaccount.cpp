// Created by Oleksandra Baga
#include "bankaccount.h"
#include <string>
#include <QtDebug>

std::vector<BankAccount>BankAccount::AllBankAccounts = std::vector<BankAccount>();

// Default constructor
BankAccount::BankAccount()
{
    taxClass = 1; // default tax class
}

// This constructor assumes that it receives a valid query
// pointing at some row of data from BankAccount table
BankAccount::BankAccount(QSqlRecord &query)
{
    using namespace std;

    QString q_iban = query.value(0).toString();
    QString q_aid = query.value(1).toString();
    taxClass = query.value(2).toInt();

    // qs.toUtf8().constData() is a way to convert QString to std::string
    IBAN = BankAccountID(q_iban.toUtf8().constData());
    accountID = AccountID(q_aid.toUtf8().constData());
    // account = AccountID(q_aid.toUtf8().constData());
    account = NULL;
}

void BankAccount::setIBAN(BankAccountID IBAN)
{
    this->IBAN = IBAN;
}

BankAccountID BankAccount::getIBAN()
{
    return IBAN;
}

void BankAccount::setAccountID(AccountID accountID)
{
    this->accountID = accountID;
}
AccountID BankAccount::getAccountID()
{
    return accountID;
}

void BankAccount::setAccount(Account *account)
{
    this->account = account;
}

Account *BankAccount::getAccount()
{
    return account;
}

void BankAccount::setTaxClass(int taxClass)
{
    this->taxClass = taxClass;
    qDebug() << "New tax class is set:" << this->taxClass;
}

int BankAccount::getTaxClass()
{
    qDebug() << "Tax class is:" << taxClass;
    return taxClass;
}

bool BankAccount::linkAccount()
{
    bool ret = false;

    for (size_t i = 0; i < Account::AllAccounts.size(); i++)
    {
       if (Account::AllAccounts[i].getAccountID().toQstring() == accountID.toQstring())
       {
          setAccount(&Account::AllAccounts[i]);
          qDebug() << "Account is set to AccountID:" << Account::AllAccounts[i].getAccountID().toQstring();
          ret = true;
       }
    }
    return ret;
}

bool BankAccount::linkProvidedAccount(AccountID accountID)
{
    bool ret = false;

    for (size_t i = 0; i < Account::AllAccounts.size(); i++)
    {
       if (Account::AllAccounts[i].getAccountID().toQstring() == accountID.toQstring())
       {
          setAccount(&Account::AllAccounts[i]);
          qDebug() << "Account is set to AccountID:" << Account::AllAccounts[i].getAccountID().toQstring();
          ret = true;
       }
    }
    return ret;
}
