#include "actuator.h"
#include <QDebug>

Actuator::Actuator()
{

}

Actuator::~Actuator()
{
     qDebug() << "This Actuator is deleted ";
}

void Actuator:: setActuatorState(State actuatorState)
{
     this->actuatorState = actuatorState;
     qDebug() << "The Actuatorstate is set : " << this->actuatorState;
}

void Actuator:: setActuatorDuration(unsigned int actuatorDuration)
{
    this->actuatorDuration = actuatorDuration;
    qDebug() << "The Actuatorduration is set : " << this->actuatorDuration;
}

void Actuator:: setActuatorType(ActuatorType actuatorType)
{
    this->actuatorType = actuatorType;
    qDebug() << "The Actuatortype is set : " << this->actuatorType;
}

ActuatorType Actuator::getActuatorType() const
{
    qDebug() << "The Actuatortype is : " << this->actuatorType;
    return this->actuatorType;
}

unsigned int Actuator::getActuatorDuration() const
{
    qDebug() << "The Actuatorduration is : " << this->actuatorDuration;
    return this->actuatorDuration;
}

State Actuator::getActuatorState() const
{
    qDebug() << "The Actuatorstate is : " << this->actuatorState;
    return this->actuatorState;
}
