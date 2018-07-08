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
        int getCurrentTemperature() const;
        void setCurrentTemperature(int currentTemperature);
        void setReferenceTemperature(int currentTemperature);
        int getReferenceTemperature() const;
        bool compareTemperature();
};

#endif // TEMPERATURSENSOR_H
