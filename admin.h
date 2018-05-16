#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "card.h"

class Admin : public Person
{
    public:
         Admin();
        ~Admin();
        Card createCard();
        void deactivateCard(Card c);
        void createBill();
};

#endif // ADMIN_H
