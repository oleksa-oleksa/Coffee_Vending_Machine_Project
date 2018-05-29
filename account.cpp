#include "account.h"
const float CREDIT_LIMIT = 10.0;

Account::Account()
{
    //commenttar
}

AccountStatus Account::getAccountStatus()
{
    return state;
}

void Account::setAccountStatus(Card card)
{
}

bool Account::addCredit(float amount)
{
    if (getAccountStatus() != ACTIVE_OK)
    {
        return false;
    }

    credit += amount;
    return true;
}

void Account::block()
{
    state = BLOCKED_UNPAID;
}

void Account::activate()
{
    state = ACTIVE_OK;
}
