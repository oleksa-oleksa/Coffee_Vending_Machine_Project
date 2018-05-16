#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "state.h"
#include <string>
#include "actuatortype.h"

class Actuator
{
    ActuatorType actuatorType;
    unsigned int act_duration = 0;

    public:
        Actuator();
        void act(State state, unsigned int duration);
        ActuatorType getActuatorType() const;
        unsigned int getActuatorDuration() const;
        int getActuatorState() const;
        void setActuatorState(int state);
        void setActuatorDuration(unsigned int duration);
        void setActuatorType(string name);
        void setActuatorType(std::string name);
};

#endif // ACTUATOR_H
