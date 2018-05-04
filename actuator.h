#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "state.h"
#include <string>
#include "actuatortype.h"

class Actuator
{
    public:
        Actuator();
        void act(State state, unsigned int duration);
        ActuatorType getActuatorType() const;
        unsigned int getActuatorDuration() const;
        int getActuatorState() const;
        void setActuatorState(int state);
        void setActuatorDuration(unsigned int duration);
        void setActuatorType(std::string name);

    private:
        ActuatorType actuatorType;
        unsigned int act_duration = 0;
};

#endif // ACTUATOR_H
