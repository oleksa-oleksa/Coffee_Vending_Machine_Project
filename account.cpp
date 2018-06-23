// Created by Oleksandra Baga
#include "account.h"
#include "personid.h"
#include "person.h"
#include <QtDebug>
const float CREDIT_LIMIT = 10.0;

std::vector<Account>Account::AllAccounts = std::vector<Account>();

Account::Account()
{

}

// This constructor assumes that it receives a valid query
// pointing at some row of data from Account table
Account::Account(QSqlRecord &query)
{
    using namespace std;

    QString q_aid = query.value(0).toString();
    QString q_pid = query.value(1).toString();
    QString q_baid = query.value(2).toString();
    credit = query.value(3).toDouble();
    state = (AccountStatus)query.value(4).toInt();;

    accountID = AccountID(q_aid.toUtf8().constData());

    PersonID personID = PersonID(q_pid.toUtf8().constData());
    linkOwner(personID);
    BankAccountID iban = BankAccountID(q_baid.toUtf8().constData());
    linkBankAccount(iban);
}

Account::Account(Person *Employee, BankAccount *Ba)
{
    credit = 0.0;
    state = ACTIVE_OK;
    owner = Employee;
    ba = Ba;
}

AccountStatus Account::getAccountStatus()
{
    return state;
}


void Account::setAccountStatus(AccountStatus state)
{
    this->state = state;
    qDebug() << "Account status is now: " << state;
}

bool Account::checkCreditLimit(double amount)
{
    if (credit >= CREDIT_LIMIT)
    {
        qDebug() << "Limit: " << CREDIT_LIMIT  << " is reached. Oops!";
        blockAccount();
        qDebug() << "Account blocked, please contact your system administrator :)";
        return false;
    }

    if ((credit + amount) >= CREDIT_LIMIT)
    {
        qDebug() << "You can not buy this drink, the limit will be exceeded!";
        double tmp = CREDIT_LIMIT -  getAccountCredit();
        qDebug() << tmp << "€ is available for drink purchase!";
        return false;
    }
    return true;
}


double Account::getAccountCredit()
{
   return credit;
}

Person *Account::getOwner()
{
    qDebug() << "Account owner is: " << owner;
    return owner;
}

void Account::setOwner(Person *owner)
{
    this->owner = owner;
    qDebug() << "Account owner is: " << this->owner->getID().toQstring();
}

BankAccount *Account::getBankAccount()
{
    qDebug() << "Associated bank account is: " << ba;
    return ba;
}

void Account::setAccountID(AccountID accountID)
{
   this->accountID = accountID;
}

AccountID Account::getAccountID()
{
    qDebug() << "Associated account is: " << accountID.toQstring();
    return accountID;
}

void Account::setBankAccount(BankAccount *ba)
{
    this->ba = ba;
    qDebug() << "Associated bank account is: " << this->ba->getIBAN().toQstring();
}

// Simple setter
void Account::setAccountCredit(double credit)
{
    this->credit = credit;
    qDebug() << "Setter: credit is set: " << credit;

}

// increases credit
bool Account::addCredit(double amount)
{
    if (getAccountStatus() != ACTIVE_OK)
    {
        return false;
    }

    // if credit limit is not reached, user can buy a new drink
    if (checkCreditLimit(amount))
    {
        // Obtaining actual credit
        double tmp_cr = getAccountCredit();
        // increasing
        tmp_cr += amount;
        // setting
        setAccountCredit(amount);

        qDebug() << "Credit: " << amount  << " added to the card";
        qDebug() << "New credit: " <<  credit;
        return true;
    }
    else
    {
        blockAccount();
        qDebug() << "Payment attemt is blocked, credit limit is reached " <<  credit;
        return false;
    }
}

void Account::activateAccount()
{
    setAccountStatus(ACTIVE_OK);
    qDebug() << "Account is activated";
}

void Account::deactivateAccount()
{
    setAccountStatus(DEACTIVATED_OLD);
    qDebug() << "Account is deactivated";
}

void Account::blockAccount()
{
    setAccountStatus(BLOCKED_UNPAID);
    qDebug() << "Account is blocked";
}

bool Account::linkOwner(PersonID personID)
{
    bool ret = false;

    for (size_t i = 0; i < Person::AllEmployee.size(); i++)
    {
       if (Person::AllEmployee[i].getID().toQstring() == personID.toQstring())
       {
          setOwner(&Person::AllEmployee[i]);
          qDebug() << "Owner is set to PersonID:" << Person::AllEmployee[i].getID().toQstring();
          ret = true;
       }
    }
    return ret;
}

bool Account::linkBankAccount(BankAccountID iban)
{
    bool ret = false;

    for (size_t i = 0; i < BankAccount::AllBankAccounts.size(); i++)
    {
       if (BankAccount::AllBankAccounts[i].getIBAN().toQstring() == iban.toQstring())
       {
          setBankAccount(&BankAccount::AllBankAccounts[i]);
          qDebug() << "Bank account is set to IBAN:" << BankAccount::AllBankAccounts[i].getIBAN().toQstring();
          ret = true;
       }
    }
    return ret;
}
