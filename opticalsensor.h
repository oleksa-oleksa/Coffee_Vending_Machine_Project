// Exisiting file implemented for project by Oleksandra Baga
#ifndef OPTICALSENSOR_H
#define OPTICALSENSOR_H
#include "sensor.h"

class OpticalSensor : public Sensor
{
    private:
        bool isObjectDetected;
        int distanceToObject;

    public:
        OpticalSensor();
        OpticalSensor(bool);
        ~OpticalSensor();

        bool getOpticalValue();
        int getDistanceToObject();
        void setDistanceToObject(int distanceToObject);
};

#endif // OPTICALSENSOR_H
