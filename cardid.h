#ifndef CARDID_H
#define CARDID_H

#include <iostream>

class CardID
{
    private:
        std::string id;
    public:
        CardID();
        void createRandomID();
};

#endif // CARDID_H
