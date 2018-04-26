#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "state.h"
class ActuatorType;

class Actuator
{
public:
    Actuator();
    ~Actuator();
    void act(State state, unsigned int duration);

private:
    ActuatorType actuatorType;
    unsigned int act_duration = 0;
};

#endif // ACTUATOR_H
