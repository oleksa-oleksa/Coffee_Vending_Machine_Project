#include "rfid_scanner.h"
#include <utility>
#include <QDebug>

using namespace std;

RFID_Scanner::RFID_Scanner()
{
    sensorType = RFID;
    sensorState = UNDEFINED;
    isCardInside = false;
    isChoiceAllowed = false;
}

RFID_Scanner::~RFID_Scanner()
{

}

bool RFID_Scanner::setIsCardInside(bool isCardInside)
{
    this->isCardInside = isCardInside;
}

bool RFID_Scanner::getIsCardInside()
{
    return isCardInside;
}

bool RFID_Scanner::getRfidValidation(Card *userCard)
{
    // CardID Validation
    for (size_t i = 0; i < Card::AllCards.size(); i++)
    {
        if ( Card::AllCards[i].getCardID().toQstring() == userCard->getCardID().toQstring())
        isChoiceAllowed = true;
    }

    // Card Status Validation
    if (userCard->getCardStatus() != ACTIVE)
    {
        return isChoiceAllowed = false;
    }

    // Account Status Validation
    if (userCard->getAccount()->getAccountStatus() != ACTIVE_OK)
    {
        return isChoiceAllowed = false;
    }

    // isEmployed Validation
    if (!userCard->getAccount()->getOwner()->getEmployed())
    {
        return isChoiceAllowed = false;
    }

    return isChoiceAllowed;
}

void RFID_Scanner::ejectCard()
{
    isCardInside = false;
    isChoiceAllowed = false;
}

bool RFID_Scanner::insertCard(Card *userCard)
{
    if (userCard == NULL)
    {
        return false;
    }

    isCardInside = true;
    qDebug() << "RFID SCANNER insertCard(): CardID is: " << userCard->getCardID().toQstring() << ", owner is " << userCard->getAccount()->getOwner()->getName().c_str();

    // After card was inserted, the RFID Scanner provides verification
    // without instructions outside
    // modifies isChoiceAllowed for InteractionUnit
    return (getRfidValidation(userCard));

}


