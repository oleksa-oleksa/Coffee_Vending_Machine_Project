#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "card.h"
#include "accountstatus.h"
#include "bankaccount.h"

class Account
{
    private:
        Card *card;
        BankAccount *bankAccount;
        double credit;
        AccountStatus state;

    public:
        Account();
        ~Account();
        AccountStatus getAccountStatus(Card card);
        void setAccountStatus(Card card);
};

#endif // ACCOUNT_H
