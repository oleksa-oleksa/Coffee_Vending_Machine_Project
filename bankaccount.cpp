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
    QDebug() << "New IBAN is set: " << IBAN;

}

std::string BankAccount::getIBAN()
{
    QDebug() << "IBAN is: " << IBAN;
    return IBAN;
}

void BankAccount::setTaxClass(int tc)
{
    taxClass = tc;
    QDebug() << "New tax class is set:" << taxClass;
}

int BankAccount::getTaxClass()
{
    QDebug() << "Tax class is:" << taxClass;
    return taxClass;
}
