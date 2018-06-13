#include "bankaccount.h"
#include <string>
#include <QtDebug>

BankAccount::BankAccount()
{
    taxClass = 1; // default tax class
}

void BankAccount::setAccount(Account *newAccount)
{
    account = newAccount;
}

Account *BankAccount::getAccount()
{
    return account;
}

void BankAccount::setIBAN(std::string iban)
{
    IBAN = iban;
    qDebug() << "New IBAN is set: " << IBAN.c_str();

}

std::string BankAccount::getIBAN()
{
    qDebug() << "IBAN is: " << IBAN.c_str();
    return IBAN;
}

void BankAccount::setTaxClass(int tc)
{
    taxClass = tc;
    qDebug() << "New tax class is set:" << taxClass;
}

int BankAccount::getTaxClass()
{
    qDebug() << "Tax class is:" << taxClass;
    return taxClass;
}
