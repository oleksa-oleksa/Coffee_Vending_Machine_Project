// Created by Oleksandra Baga
#ifndef TEMPERATURSENSOR_H
#define TEMPERATURSENSOR_H
#include "sensor.h"

class TemperaturSensor : public Sensor
{
    private:
        int referenceTemperature;
        int currentTemperature;

    public:
        TemperaturSensor();
        virtual ~TemperaturSensor();
        int getCurrentTemperature();
        void setCurrentTemperature(int currentTemperature);
        void setReferenceTemperature(int currentTemperature);
        int getReferenceTemperature();
        bool compareTemperature();
};

#endif // TEMPERATURSENSOR_H
