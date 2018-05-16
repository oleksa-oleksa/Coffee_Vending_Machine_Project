#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "state.h"
#include <string>
#include "actuatortype.h"

class Actuator
{
    ActuatorType actuatorType;
    unsigned int act_duration = 0;
    State actuatorState;

    public:
        Actuator();
        ~Actuator();
        void act(State state, unsigned int duration);
        ActuatorType getActuatorType() const;
        unsigned int getActuatorDuration() const;
        State getActuatorState() const;
        void setActuatorState(int state);
        void setActuatorDuration(unsigned int duration);
        void setActuatorType(string name);
        void setActuatorType(string name);
};

#endif // ACTUATOR_H
