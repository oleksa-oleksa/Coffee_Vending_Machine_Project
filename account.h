#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "card.h"
#include "accountstatus.h"

// test
class Card;

class Account
{
    private:
        double credit;
        AccountStatus state;

    public:
        Account();
        AccountStatus getAccountStatus();
        double getAccountCredit();
        void setAccountStatus(Card card);
        bool addCredit(float amount);
        void block();
        void activate();
};

#endif // ACCOUNT_H
