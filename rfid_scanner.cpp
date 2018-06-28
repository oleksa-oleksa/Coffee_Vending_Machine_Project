#include "rfid_scanner.h"
#include <utility>
#include <QDebug>

using namespace std;

RFID_Scanner::RFID_Scanner()
{
    sensorType = RFID;
    sensorState = UNDEFINED;

/*
// For testing:
    Card testCard;
// insert testcard to cardsDatabase
    cardsDatabase[testCard] = true;
*/
}
/*
RFID_Scanner::RFID_Scanner( FILE* )
{
    FILE *cards = fopen(./"cardsDB.txt");
    ...
}
*/

RFID_Scanner::~RFID_Scanner()
{

}

bool RFID_Scanner::getRfidValidation(Card *card)
{
    bool ret = false;

    // CardID Validation
    for (size_t i = 0; i < Card::AllCards.size(); i++)
    {
        if ( Card::AllCards[i].getCardID().toQstring() == card->getCardID().toQstring())
        ret = true;
    }

    // Card Status Validation
    if (card->getCardStatus() != ACTIVE)
    {
        return false;
    }

    // Account Status Validation
    if (card->getAccount()->getAccountStatus() != ACTIVE_OK)
    {
        return false;
    }

    // isEmployed Validation
    if (!card->getAccount()->getOwner()->getEmployed())
    {
        return false;
    }
    return ret;
}

void RFID_Scanner::registerNewCard( Card& newCard )
{

}


