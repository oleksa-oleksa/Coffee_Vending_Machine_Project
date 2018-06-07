#ifndef FLOWMETER_H
#define FLOWMETER_H
#include "sensor.h"

class Flowmeter : public Sensor
{
    private:
        double flow;

    public:
        Flowmeter();
        Flowmeter(double);
        virtual ~Flowmeter();

        double getFlow();
};

#endif // FLOWMETER_H
