#ifndef TEMPERATURSENSOR_H
#define TEMPERATURSENSOR_H
#include "sensor.h"

class TemperaturSensor : public Sensor
{
    private:
        double temperature;

    public:
        TemperaturSensor();
        TemperaturSensor(double);
        virtual ~TemperaturSensor();

        double getTemperature();
};

#endif // TEMPERATURSENSOR_H
