// Created by Oleksandra Baga
#ifndef WATERHEATER_H
#define WATERHEATER_H
#include "actuator.h"
#include "temperatursensor.h"
#include <QObject>
#include <QTimer>

#define HEATING_SPEED_MS 50

class Waterheater : public QObject, public Actuator
{
    Q_OBJECT

    private:
        int idleTemperature;
        int workTemperature;
        int currentTemperature;
        bool isHeating;
        TemperaturSensor temperatureSensor;



    public:
        Waterheater();
        virtual ~Waterheater();

        void heatWater();
        void setWorkTemperature(int workTemperature);
        void setCurrentTemperature(int currentTemperature);
        void setIdleTemperature(int idleTemperature);
        int getWorkTemperature();
        int getCurrentTemperature();
        int getIdleTemperature();
        int calculateHeatingTime();
        bool getIsHeating();

    public slots:
    bool heatingDone();

};

#endif // WATERHEATER_H
