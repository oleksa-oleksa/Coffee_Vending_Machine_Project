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

void Actuator:: setActuatorState(State actuator_state)
{
    this->actuator_state = actuator_state;
}

void Actuator:: setActuatorDuration(unsigned int actuator_duration)
{
    this->actuator_duration = actuator_duration;
}

void Actuator:: setActuatorType(ActuatorType actuator_Type)
{
    this->actuator_Type = actuator_Type;
}
