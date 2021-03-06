// Exisiting file implemented for project by Oleksandra Baga
#include "rfid_scanner.h"
#include <utility>
#include <QDebug>


using namespace std;

RFID_Scanner::RFID_Scanner() {
    sensorType = RFID;
    sensorState = UNDEFINED;
    isCardInside = false;
    isChoiceAllowed = false;
}

RFID_Scanner::~RFID_Scanner() {

}

void RFID_Scanner::setIsCardInside(bool isCardInside) {
    this->isCardInside = isCardInside;
}

bool RFID_Scanner::getIsCardInside() const {
    return isCardInside;
}

bool RFID_Scanner::getRfidValidation(Card *userCard) {
    if (userCard == NULL) {
        return false;
    }

    // CardID Validation
    for (size_t i = 0; i < Card::AllCards.size(); i++) {
        if (Card::AllCards[i].getCardID().toQstring() == userCard->getCardID().toQstring()) {
            isChoiceAllowed = true;
            break;
        }
    }

    // Card Status Validation
    if (userCard->getCardStatus() != ACTIVE) {
        qDebug() << "RFID SCANNER ERROR: card status is: " << userCard->printCardStatus();
        return isChoiceAllowed = false;
    }

    // Account Status Validation
    if (userCard->getAccount()->getAccountStatus() != ACTIVE_OK) {
        qDebug() << "RFID SCANNER ERROR: Acount status is: " << userCard->getAccount()->printAccountStatus();
        return isChoiceAllowed = false;
    }

    // isEmployed Validation
    if (!userCard->getAccount()->getOwner()->getEmployed()) {
        qDebug() << "RFID SCANNER ERROR: Employed flag is: " << userCard->getAccount()->getOwner()->getEmployed();
        return isChoiceAllowed = false;
    }

    return isChoiceAllowed;
}

void RFID_Scanner::ejectCard() {
    qDebug() << "RFID SCANNER: Card ejected";
    isCardInside = false;
    isChoiceAllowed = false;
}

bool RFID_Scanner::insertCard(Card *userCard) {
    if (userCard == NULL) {
        return false;
    }

    isCardInside = true;
    qDebug() << "RFID SCANNER insertCard(): CardID is: " << userCard->getCardID().toQstring() << ", owner is " << userCard->getAccount()->getOwner()->getName().c_str();

    // After card was inserted, the RFID Scanner provides verification
    // without any additional calls from outside
    // modifies isChoiceAllowed for InteractionUnit
    return (getRfidValidation(userCard));
}

bool RFID_Scanner::isValidCardInside() {
    return isCardInside && isChoiceAllowed;
}

// On start init function
CardHolderState RFID_Scanner::InitRFID() {
    if (isValidCardInside()) {
        qDebug() << "RFID SCANNER: Valid card inside";
        return VALID_CARD_INSIDE;
    }
    else {
        qDebug() << "RFID SCANNER: No card detected";
        return NO_CARD;
    }
}
