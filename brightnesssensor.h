#ifndef BRIGHTNESSSENSOR_H
#define BRIGHTNESSSENSOR_H
#include "sensor.h"

class BrightnessSensor : public Sensor
{
    private:
        unsigned int brightness;

    public:
        BrightnessSensor();
        BrightnessSensor(unsigned int);
        virtual ~BrightnessSensor();

        unsigned int getBrightness();
};

#endif // BRIGHTNESSSENSOR_H
