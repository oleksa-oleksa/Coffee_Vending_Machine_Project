#include "dc_motor.h"

DC_Motor::DC_Motor()
{
    //this->actuator_duration =
    actuator_state = UNDEFINED;
    actuator_Type = DC_MOTOR;

}

DC_Motor::~DC_Motor()
{

}

ActuatorType DC_Motor::getActuatorType() const
{
    return actuator_Type;
}

unsigned int DC_Motor:: getActuatorDuration() const
{
    return actuator_duration;
}

State DC_Motor:: getActuatorState() const
{
    return actuator_state;
}

void DC_Motor:: setActuatorState(State actuator_state)
{
    this->actuator_state = actuator_state;
}

void DC_Motor:: setActuatorDuration(unsigned int actuator_duration)
{
    this->actuator_duration = actuator_duration;
}

void DC_Motor:: setActuatorType(ActuatorType actuator_Type)
{
    this->actuator_Type = actuator_Type;
}

void DC_Motor:: start()
{
  //to implement
}

void DC_Motor::stop()
{
  //to implement
}
