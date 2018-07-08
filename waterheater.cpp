// Created by Oleksandra Baga
#include "waterheater.h"
#include "QDebug"
#include <math.h>
#include <QTimer>

Waterheater::Waterheater() {
    actuatorState = UNDEFINED;
    actuatorType = WATERHEATER;
    idleTemperature = 60;
    workTemperature = 60;
    currentTemperature = idleTemperature;
}

Waterheater::~Waterheater() {

}

void Waterheater::heatWater() {
    qDebug() << "WATER HEATER: Starting water heating";

    temperatureSensor.setReferenceTemperature(workTemperature);
    temperatureSensor.setCurrentTemperature(idleTemperature);

    if (!temperatureSensor.compareTemperature()) {
        qDebug() << "WATER HEATER: The water will be heated from " << idleTemperature << " to " << workTemperature;
        int time = calculateHeatingTime() + HEATING_SPEED_MS; // additional delay for exceedig the reference
        qDebug() << "WATER HEATER: Realtime heating simulation started...";
        isHeating = true;
        QTimer::singleShot(time, this, &Waterheater::heatingDone);
    }
}

bool Waterheater::getIsHeating() const {

    return isHeating;
}

bool Waterheater::heatingDone() {

    isHeating = false;

    currentTemperature = workTemperature;

    temperatureSensor.setCurrentTemperature(currentTemperature);
    if (temperatureSensor.compareTemperature()) {
        qDebug() << "WATER HEATER: Realtime heating simulation done. Water heated to" << currentTemperature << "degrees";
        return true;
    } else {
        qDebug() << "WATER HEATER: Water heater does not heat a water. Aborted...";
        return false;
    }
}

int Waterheater::calculateHeatingTime() {

    int time = 0;

    if (!temperatureSensor.compareTemperature()) {
        time = (workTemperature - idleTemperature) * HEATING_SPEED_MS;
        qDebug() << "WATER HEATER: Heating will last" << time << " ms.";
    }
    return time;
}

void Waterheater::setWorkTemperature(int workTemperature) {
    this->workTemperature = workTemperature;
}

int Waterheater::getWorkTemperature() const {
    return workTemperature;
}


void Waterheater::setCurrentTemperature(int currentTemperature) {
    this->currentTemperature = currentTemperature;
}

void Waterheater::setIdleTemperature(int idleTemperature) {
    this->idleTemperature = idleTemperature;
}

int Waterheater::getCurrentTemperature() const {
    return currentTemperature;
}

int Waterheater::getIdleTemperature() const {
       return idleTemperature;
}















