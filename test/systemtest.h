#ifndef SYSTEMTEST_H
#define SYSTEMTEST_H
#include <QtTest/QtTest>
#include <QObject>
#include "serviceroutine.h"

#include "button.h"
#include "controlunit.h"
#include "rfid_scanner.h"
#include "flowmeter.h"
#include "opticalsensor.h"
#include "temperatursensor.h"
#include "brightnesssensor.h"
#include "lcd_display.h"
#include "dc_motor.h"
#include "waterheater.h"
#include "milkmaker.h"

class SystemTest: public QObject
{
    Q_OBJECT
    public:
        void createAllDependencies();
        void cleanup();
        // global buttons:
        Button moreSugar;
        Button lessSugar;
        Button moreMilk;
        Button lessMilk;
        Button coffee;
        Button cappuccino;
        Button espresso;
        Button latteMacchiato;
        Button cacao;
        Button hotWater;
        Button bigPortion;
        Button cancel;
        Button start;

        // global sensors and actuators
        ControlUnit control;

        RFID_Scanner cardScanner;
        Flowmeter flow;
        OpticalSensor opticalSensor;
        TemperaturSensor temperatureSensor;
        BrightnessSensor brightSensor;

        LCD_Display display;
        DC_Motor motor[4];
        Waterheater heater;
        Milkmaker milkMaker;

        SystemTest();
    private slots:
        void systemTest();
};
#endif // SYSTEMTEST_H
