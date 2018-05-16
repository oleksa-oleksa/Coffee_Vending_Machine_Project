#include <iostream>
#include "actuator.h"
using namespace std;

Actuator::Actuator()
{
    act(state, duration);
}

Actuator::~Actuator()
{
    cout << "end" << endl;
}

State Actuator::getActuatorState() const
{
    return actuatorState;
}

void Actuator::setActuatorState(State act_State)
{
    actuatorState = act_State;
}

ActuatorType Actuator::getActuatorType() const
{
    return actuatorType;
}

 unsigned int Actuator::getActuatorDuration() const
{
    return act_duration;
}

void Actuator::act(State state, unsigned int duration)
{
    setActuatorDuration(duration);
    setActuatorState(state);
}

void Actuator::setActuatorType(string name )
{
    actuatorType = name;
}

void Actuator::setActuatorDuration(unsigned int duration)
{
    act_duration = duration;
}
