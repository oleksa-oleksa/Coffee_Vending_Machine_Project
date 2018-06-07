#include "waterheater.h"

Waterheater::Waterheater()
{
    //actuator_duration = ;
    actuator_state = UNDEFINED;
    actuator_Type = WATERHEATER;
}

Waterheater::~Waterheater()
{
  //to implement
}

ActuatorType Waterheater::getActuatorType() const
{
  return this->actuator_Type;
}

unsigned int Waterheater::getActuatorDuration() const
{
  return this->actuator_duration;
}

State Waterheater::getActuatorState() const
{
  return this->actuator_state;
}

int Waterheater::get_water_temperature() const
{
  return water_temperature;
}

void Waterheater::set_water_temperature(int water_temperature)
{
  this->water_temperature = water_temperature;
}

void Waterheater::setActuatorState(State actuator_state)
{
  this->actuator_state = actuator_state;
}

void Waterheater::setActuatorDuration(unsigned int actuator_duration)
{
  this->actuator_duration = actuator_duration;
}

void Waterheater::setActuatorType(ActuatorType actuator_Type)
{
  this->actuator_Type = actuator_Type;
}




















