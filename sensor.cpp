#include "sensor.h"

Sensor::Sensor() {

}

Sensor::~Sensor() {

}

SensorType Sensor::getSensorType() const {
    return sensorType;
}

State Sensor::getSensorState() const {
    return sensorState;
}

void Sensor::setSensorType(SensorType sensorType) {
   this->sensorType = sensorType;

   QString str_type = printSensorType();
   qDebug() << "SENSOR: Type is set: " << str_type;
}

void Sensor::setSensorState(State sensorState) {
    this->sensorState = sensorState;

    QString str_state = printSensorState();
    QString str_type = printSensorType();
    qDebug() << "SENSOR: State of " << str_type << "is set: " << str_state;
}

QString Sensor::printSensorState() {
    QString str;
    switch (sensorState) {
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


QString Sensor::printSensorType() {
    QString str;
    switch (sensorType) {
    case (RFID):
        str = "RFID SCANNER";
        return str;
    case (OPTICAL):
        str = "OPTICAL SENSOR";
        return str;
    case (PRESSURE):
        str = "PRESSURE";
        return str;
    case (TEMPERATURE):
        str = "TEMPERATURE";
        return str;
    case (FLOW):
        str = "FLOW";
        return str;
    case (BRIGHTNESS):
        str = "BRIGHTNESS";
        return str;
    case (BUTTON):
        str = "BUTTON";
        return str;
    default:
        break;
    }
    return "UNDEFINED";
}
