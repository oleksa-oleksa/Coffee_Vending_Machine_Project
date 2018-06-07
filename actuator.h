#ifndef ACTUATOR_H
#define ACTUATOR_H
#include <string>
#include "state.h"
#include "actuatortype.h"

class Actuator
{
    protected:
    ActuatorType actuator_Type;
    unsigned int actuator_duration = 0;
    State actuator_state;

    public:
        Actuator();
        virtual ~Actuator();
        virtual ActuatorType getActuatorType() const = 0;
        virtual unsigned int getActuatorDuration() const = 0;
        virtual State getActuatorState() const = 0;
        virtual void setActuatorState(State actuator_state) = 0 ;
        virtual void setActuatorDuration(unsigned int actuator_duration) = 0 ;
        virtual void setActuatorType(ActuatorType actuator_Type) = 0;
};

#endif // ACTUATOR_H
