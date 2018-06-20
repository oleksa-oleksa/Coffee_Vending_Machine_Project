#ifndef CARDID_H
#define CARDID_H
#include <iostream>
#include <QString>

#define CARD_ID_LEN 12 // creates 16 signs for id

class CardID
{
    private:
        std::string cardID;
    public:
        CardID(std::string id);
        CardID();
        QString toQstring();
};

#endif // CARDID_H
