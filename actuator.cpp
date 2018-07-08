#include "actuator.h"
#include <QDebug>

Actuator::Actuator() {

}

Actuator::~Actuator() {

}

void Actuator:: setActuatorState(State actuatorState) {
     this->actuatorState = actuatorState;

     QString str_state = printActuatorState();
     QString str_type = printActuatorType();
     qDebug() << "ACTUATOR: State of " << str_type << "is set: " << str_state;
}

void Actuator:: setActuatorDuration(unsigned int actuatorDuration) {
    this->actuatorDuration = actuatorDuration;
    qDebug() << "ACTUATOR: Duration is set: " << this->actuatorDuration;
}

void Actuator:: setActuatorType(ActuatorType actuatorType) {
    this->actuatorType = actuatorType;
    qDebug() << "ACTUATOR: Type is set: " << this->actuatorType;
}

ActuatorType Actuator::getActuatorType() const {
    return this->actuatorType;
}

unsigned int Actuator::getActuatorDuration() const {
    return this->actuatorDuration;
}

State Actuator::getActuatorState() const {
    return this->actuatorState;
}

QString Actuator::printActuatorState() {
    QString str;
    switch (actuatorState) {
    case (OK):
        str = "OK";
        return str;
    case (UNDEFINED):
        str = "UNDEFINED";
        return str;
    case (ALARM):
        str = "ALARM";
        return str;
    default:
        break;
    }
    return "UNDEFINED";
}


QString Actuator::printActuatorType() {
    QString str;
    switch (actuatorType) {
    case (DC_MOTOR):
        str = "DC_MOTOR";
        return str;
    case (LCD):
        str = "LCD";
        return str;
    case (MILKMAKER):
        str = "MILKMAKER";
        return str;
    case (WATERHEATER):
        str = "WATERHEATER";
        return str;
    case (BREWGROUP):
        str = "BREWGROUP";
        return str;
    default:
        break;
    }
    return "UNDEFINED";
}
