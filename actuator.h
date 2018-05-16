#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "state.h"
#include <string>
class ActuatorType;

class Actuator
{
    ActuatorType actuatorType;
    unsigned int act_duration = 0;

    public:
        Actuator();
        ~Actuator();
        void act(State state, unsigned int duration);
        enum ActuatorType getActuatorType() const;
        unsigned int getActuatorDuration() const;
        int getActuatorState() const;
        void setActuatorState(int state);
        void setActuatorDuration(unsigned int duration);
        void setActuatorType(string name);
};

#endif // ACTUATOR_H
