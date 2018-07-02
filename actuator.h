#ifndef ACTUATOR_H
#define ACTUATOR_H
#include <string>
#include "state.h"
#include "actuatortype.h"
#include <QString>

class Actuator
{
    protected:
        ActuatorType actuatorType;
        unsigned int actuatorDuration = 0;
        State actuatorState;

    public:
        Actuator();
        virtual ~Actuator();
        virtual ActuatorType getActuatorType() const;
        virtual unsigned int getActuatorDuration() const;
        virtual State getActuatorState() const;
        virtual void setActuatorState(State actuatorState);
        virtual void setActuatorDuration(unsigned int actuatorDuration);
        virtual void setActuatorType(ActuatorType actuatorType);
        QString printActuatorState();
        QString printActuatorType();
};

#endif // ACTUATOR_H
