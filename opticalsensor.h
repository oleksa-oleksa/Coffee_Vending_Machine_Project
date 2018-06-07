#ifndef OPTICALSENSOR_H
#define OPTICALSENSOR_H
#include "sensor.h"

class OpticalSensor : public Sensor
{
    private:
        bool isFree;

    public:
        OpticalSensor();
        OpticalSensor(bool);
        ~OpticalSensor();

        bool getOpticalValue();


};

#endif // OPTICALSENSOR_H
