#ifndef ADMIN_H
#define ADMIN_H
#include "card.h"

class Admin
{
public:
     Admin();
    ~Admin();
    Card createCard();
    deactivateCard(card c);
    createBill();
};

#endif // ADMIN_H
