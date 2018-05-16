#ifndef LED_H
#define LED_H
#include "actuator.h"

class LED: public Actuator
{
    public:
        LED();
        ~LED();
};

#endif // LED_H
