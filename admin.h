#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "card.h"
#include "account.h"

class Admin : public Person
{
    public:
         Admin();
        ~Admin();
        Card createCard();
        void deactivateCard(Card c);
        void createBill();
        Account createAccount();
        void activateAccount(Account account);
        void deactivateAccount(Account account);
        void blockAccount(Account account);
};

#endif // ADMIN_H
