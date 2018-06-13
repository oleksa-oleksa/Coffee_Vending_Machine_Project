#include "account.h"
#include <QtDebug>
const float CREDIT_LIMIT = 10.0;

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


void Account::setAccountStatus(AccountStatus newState)
{
    state = newState;
    qDebug() << "Account status is now: " << state;
}

bool Account::checkCreditLimit()
{
    if (credit >= CREDIT_LIMIT)
    {
        qDebug() << "Limit: " << CREDIT_LIMIT  << " is reached. Oops!";
        blockAccount();
        qDebug() << "Account blocked, please contact your system administrator :)";
        return false;
    }
    return true;
}


double Account::getAccountCredit()
{
   return credit;
}

void Account::setAccountCredit(double amount)
{
    credit += amount;
}

bool Account::addCredit(double amount)
{
    if (getAccountStatus() != ACTIVE_OK)
    {
        return false;
    }

    // if credit limit is not reached, user can buy a new drink
    if (checkCreditLimit())
    {
        setAccountCredit(amount);
        qDebug() << "Credit: " << amount  << " added to the card";
        qDebug() << "New credit: " <<  credit;
        return true;
    }
    else
    {
        blockAccount();
        qDebug() << "Attemt blocked, credit limit is reached " <<  credit;
        return false;
    }
}

void Account::activateAccount()
{
    setAccountStatus(ACTIVE_OK);
}

void Account::deactivateAccount()
{
    setAccountStatus(DEACTIVATED_OLD);
}

void Account::blockAccount()
{
    setAccountStatus(BLOCKED_UNPAID);
}
