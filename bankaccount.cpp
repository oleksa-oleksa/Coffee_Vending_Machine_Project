#include "bankaccount.h"
#include <string>
#include <QtDebug>

BankAccount::BankAccount()
{
    taxClass = 1; // default tax class
}

void BankAccount::setAccount(Account *account)
{
    this->account = account;
}

Account *BankAccount::getAccount()
{
    return account;
}

void BankAccount::setIBAN(BankAccountID IBAN)
{
    this->IBAN = IBAN;
}

BankAccountID BankAccount::getIBAN()
{
    return IBAN;
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
