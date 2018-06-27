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
//   if ( cardsDatabase.find(usercard) == cardsDatabase.end())
        qDebug() << "Error: Not yet implemented!";

// return cardsDatabase[usercard];
}

void RFID_Scanner::registerNewCard( Card& newCard )
{

}


