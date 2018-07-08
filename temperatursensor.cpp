// Created by Oleksandra Baga
#include "temperatursensor.h"
#include "QDebug"

TemperaturSensor::TemperaturSensor() {
    sensorType = TEMPERATURE;
    sensorState = UNDEFINED;
    referenceTemperature = 0;
    currentTemperature = 0;
}


TemperaturSensor::~TemperaturSensor() {

}

bool TemperaturSensor::compareTemperature() {

    if (referenceTemperature <= currentTemperature) {
        qDebug() << "TEMPERATUR SENSOR: Reference temperature is reached";
        return true;
    }
    else {
        qDebug() << "TEMPERATUR SENSOR: Reference temperature is higher";
        return false;
    }
}

int TemperaturSensor::getCurrentTemperature() const {
    return currentTemperature;
}

void TemperaturSensor::setCurrentTemperature(int currentTemperature) {
    this->currentTemperature = currentTemperature;
}

void TemperaturSensor::setReferenceTemperature(int referenceTemperature) {
    this->referenceTemperature = referenceTemperature;
}

int TemperaturSensor::getReferenceTemperature() const {

    return referenceTemperature;
}

