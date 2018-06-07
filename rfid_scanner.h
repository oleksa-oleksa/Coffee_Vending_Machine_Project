#ifndef RFID_SCANNER_H
#define RFID_SCANNER_H
#include "sensor.h"

class RFID_Scanner : public Sensor
{
    private:
        bool rfidValid;
        std::string rfidUID;

    public:
        RFID_Scanner();
        RFID_Scanner(bool, std::string);
        virtual ~RFID_Scanner();

        bool getRfidValidation();
        std::string getRfidUID();

};

#endif // RFID_SCANNER_H
