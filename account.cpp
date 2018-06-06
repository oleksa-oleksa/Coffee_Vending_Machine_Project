#include "account.h"
#include <QtDebug>
const float CREDIT_LIMIT = 10.0;

Account::Account()
{
    //commenttar
}

AccountStatus Account::getAccountStatus()
{
    return state;
}

void Account::setAccountStatus()
{
    if (credit >= CREDIT_LIMIT)
    {
        qDebug() << "Limit: " << CREDIT_LIMIT  << " is reached. Oops!";
        blockAccount();
    }
}

bool Account::addCredit(float amount)
{
    if (getAccountStatus() != ACTIVE_OK)
    {
        return false;
    }

    double checkCredit = getAccountCredit();
    credit += amount;
    qDebug() << "Credit: " << amount  << " added to the card";
    qDebug() << "New credit: " <<  credit;
    return true;
}


double Account::getAccountCredit()
{
   return credit;
}

void Account::setAccountCredit()
{

}


void Account::activateAccount()
{

}

void Account::deactivateAccount()
{
    state = DEACTIVATED_OLD;
}

void Account::blockAccount()
{
    state = BLOCKED_UNPAID;
}
