#include "cardid.h"
#include <iostream>
#define ID_LEN 5

CardID::CardID()
{
    createRandomID();
}

void CardID::createRandomID()
{
    std::string newID(5, '0');

    static const char alphanum[] =
            "0123456789"
            "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < ID_LEN; ++i)
        {
            newID[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        id = newID;
}
