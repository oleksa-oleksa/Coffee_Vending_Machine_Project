#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "card.h"
#include "accountstatus.h"
#include "bankaccount.h"

// test

class Account
{
public:
    Account();
    ~Account();
    AccountStatus getAccountStatus(Card card);
    void setAccountStatus(Card card);

private:
    Card *card;
    BankAccount *bankAccount;
    double credit;
    AccountStatus state;

};

#endif // ACCOUNT_H
