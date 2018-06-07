#include "milkmaker.h"
#include "actuator.h"

Milkmaker::Milkmaker()
{
    //actuator_duration =
    actuator_Type = MILKMAKER;
    actuator_state =UNDEFINED;
}

Milkmaker::~Milkmaker()
{
  //to implement
}

ActuatorType Milkmaker::getActuatorType() const
{
    return actuator_Type;
}

unsigned int Milkmaker::getActuatorDuration() const
{
    return actuator_duration;
}

State Milkmaker::getActuatorState() const
{
    return actuator_state;
}

void Milkmaker::setActuatorState(State actuator_state)
{
    this->actuator_state = actuator_state;
}

void Milkmaker::setActuatorDuration(unsigned int actuator_duration)
{
    this->actuator_duration = actuator_duration;
}

void Milkmaker::setActuatorType(ActuatorType actuator_Type)
{
  this->actuator_Type = actuator_Type;
}















