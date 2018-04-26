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
        deactivateCard(card c);
        void createBill();
};

#endif // ADMIN_H
