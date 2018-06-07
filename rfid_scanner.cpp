#include "rfid_scanner.h"

RFID_Scanner::RFID_Scanner()
{
    sensorType = RFID;
    sensorState = UNDEFINED;
    rfidValid = false;
    rfidUID = "XX XX XX XX";
}

RFID_Scanner::RFID_Scanner(bool setRfidValid, std::string setRfidUID)
{
    sensorType = RFID;
    sensorState = UNDEFINED;
    rfidValid = setRfidValid;
    rfidUID = setRfidUID;
}

RFID_Scanner::~RFID_Scanner()
{

}

bool RFID_Scanner::getRfidValidation()
{
    return this->rfidValid;
}

std::string RFID_Scanner::getRfidUID()
{
    return this->rfidUID;
}

