#ifndef LED_H
#define LED_H
#include "actuator.h"

class LED : protected Actuator
{
public:
    LED();
    virtual ~LED();
    bool startStop(int status);

private:
    int status; //für das an-und ausschalten
};

#endif // LED_H
