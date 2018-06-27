#ifndef RFID_SCANNER_H
#define RFID_SCANNER_H

#include "sensor.h"
#include "card.h"
#include <map>

class RFID_Scanner : public Sensor
{
    private:
        std::map<Card, bool> cardsDatabase;

    public:
// TODO: Implement as Singleton Class
        RFID_Scanner();
/* TODO: Read database from file:
 * RFID_Scanner( FILE* );
 */
        virtual ~RFID_Scanner();

        bool getRfidValidation(Card *card);
        void registerNewCard ( Card& );

};

#endif // RFID_SCANNER_H
