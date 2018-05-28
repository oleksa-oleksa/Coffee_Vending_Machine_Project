#ifndef BUTTON_H
#define BUTTON_H
#include "sensor.h"
class Button : public Sensor
{
public:
    Button();

    bool getSensorState() const;
    int getValue() const;
};

#endif // BUTTON_H
