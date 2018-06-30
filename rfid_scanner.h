// Exisiting file implemented for project by Oleksandra Baga
#ifndef RFID_SCANNER_H
#define RFID_SCANNER_H

#include "sensor.h"
#include "card.h"
#include <map>

class RFID_Scanner : public Sensor
{
    private:
        bool isCardInside;
        bool isChoiceAllowed;

    public:
        RFID_Scanner();
        virtual ~RFID_Scanner();

        bool setIsCardInside(bool isCardInside);
        bool getIsCardInside();
        bool getRfidValidation(Card *userCard);
        void ejectCard();
        bool insertCard(Card *userCard);
        bool isValidCardInside();

};

extern RFID_Scanner RFID_s;

#endif // RFID_SCANNER_H
