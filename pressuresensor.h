#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H
#include "sensor.h"

class PressureSensor : public Sensor
{
    private:
        double pressure;

    public:
        PressureSensor();
        PressureSensor(double);
        virtual ~PressureSensor();

        double getPressureValue();
};

#endif // PRESSURESENSOR_H
