#ifndef CONTROLUNITTEST_H
#define CONTROLUNITTEST_H
#include <QtTest/QtTest>
#include <QObject>
#include "controlunit.h"

class ControlUnitTest: public QObject
{
    Q_OBJECT

    ControlUnit *cu;
    UserChoice *choice;
    Flowmeter *flow;
    OpticalSensor *opticalSensor;
    BrightnessSensor *brightSensor;
    LCD_Display *display;
    RFID_Scanner *cardScanner;

    private slots:

    void init();
    void cleanup();


    void testControlUnitInit();
};

#endif // CONTROLUNITTEST_H
