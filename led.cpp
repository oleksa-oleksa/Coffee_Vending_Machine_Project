#include "led.h"

LED::LED()
{
    //actuator_duration;
    actuator_Type = Led;
    actuator_state = UNDEFINED;
}

LED::~LED()
{

}

ActuatorType LED::getActuatorType() const
{
    return actuator_Type;
}

unsigned int LED::getActuatorDuration() const
{
    return actuator_duration;
}

State LED::getActuatorState() const
{
    return actuator_state;
}

void LED::setActuatorState(State actuator_state)
{
    this->actuator_state = actuator_state;
}

void LED::setActuatorDuration(unsigned int actuator_duration)
{
    this->actuator_duration = actuator_duration;
}

void LED::setActuatorType(ActuatorType actuator_Type)
{
  this->actuator_Type = actuator_Type;
}

void LED::an_aus(int status)
{
  this->status = status;
}










