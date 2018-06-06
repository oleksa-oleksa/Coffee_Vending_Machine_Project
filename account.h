#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "card.h"
#include "person.h"
#include "accountstatus.h"

class Account
{
    private:
        double credit;
        AccountStatus state;
        Person owner;
    public:
        Account();
        void setAccountStatus();
        AccountStatus getAccountStatus();
        double getAccountCredit();
        void setAccountCredit();
        bool addCredit(float amount);
        void activateAccount();
        void deactivateAccount();
        void blockAccount();
};

#endif // ACCOUNT_H
