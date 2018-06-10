    #include "actuator.h"

Actuator::Actuator()
{
//  this->actuator_duration = duration;
//  this->actuator_state = state;
//  this->actuator_Type = actuator_type;
}

Actuator::~Actuator()
{

}

void Actuator:: setActuatorState(State actuatorState)
{
    this->actuatorState = actuatorState;
}

void Actuator:: setActuatorDuration(unsigned int actuatorDuration)
{
    this->actuatorDuration = actuatorDuration;
}

void Actuator:: setActuatorType(ActuatorType actuatorType)
{
    this->actuatorType = actuatorType;
}

ActuatorType Actuator::getActuatorType() const
{
    return actuatorType;
}

unsigned int Actuator::getActuatorDuration() const
{
    return actuatorDuration;
}

State Actuator::getActuatorState() const
{
    return actuatorState;
}
