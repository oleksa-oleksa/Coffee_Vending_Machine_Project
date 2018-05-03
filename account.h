#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "bankaccount.h"
#include "card.h"
#include "accountstatus.h"

// test

class Account
{
    private:
        Card *card;
       // BankAccount *bAccount;
        double credit;
        AccountStatus state;

    public:
        Account();
        ~Account();
        AccountStatus getAccountStatus(Card card);
        void setAccountStatus(Card card);
};

#endif // ACCOUNT_H
