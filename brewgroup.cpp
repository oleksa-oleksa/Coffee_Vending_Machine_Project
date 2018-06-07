#include "brewgroup.h"

Brewgroup::Brewgroup()
{

}

Brewgroup::~Brewgroup()
{

}

ActuatorType Brewgroup::getActuatorType() const
{

}

unsigned int Brewgroup::getActuatorDuration() const
{
  return this->actuator_duration;
}

State Brewgroup::getActuatorState() const
{
    return this->actuator_state;
}

void Brewgroup::setActuatorState(State actuator_state)
{
 this->actuator_state = actuator_state;
}

void Brewgroup::setActuatorDuration(unsigned int actuator_duration)
{

}

void Brewgroup::setActuatorType(ActuatorType actuator_Type)
{
  this->actuator_Type = actuator_Type;
}

void Brewgroup::start_stop(int status)
{
    this->status = status;
}
