#include "rfid_scanner.h"
#include <utility>

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

bool RFID_Scanner::getRfidValidation( Card& usercard )
{
/*
   for( std::map<Card,bool>::iterator it = cardsDatabase.begin(); it != cardsDatabase.end(); ++it) { // For each element in cardsDatabase
    {
        if ( it->first == usercard )
            return it->second;
    }
    return false;
*/
}

void RFID_Scanner::registerNewCard( Card& newCard )
{

}


