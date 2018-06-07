#ifndef PROXIMITYSENSOR_H
#define PROXIMITYSENSOR_H
#include "sensor.h"

class ProximitySensor : public Sensor
{
    private:
        double proximity;

    public:
        ProximitySensor();
        ProximitySensor(double);
        virtual ~ProximitySensor();

        double getProximity();

};

#endif // PROXIMITYSENSOR_H
