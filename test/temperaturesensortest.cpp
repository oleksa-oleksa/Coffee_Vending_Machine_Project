#include "temperaturesensortest.h"

void TemperatureSensorTest::testCompareTemperatur()
{
    TemperaturSensor temp;

    temp.setCurrentTemperature(20);
    temp.setReferenceTemperature(17);
    QCOMPARE(temp.compareTemperature(), true);

    temp.setCurrentTemperature(20);
    temp.setReferenceTemperature(20);
    QCOMPARE(temp.compareTemperature(), true);

    temp.setCurrentTemperature(15);
    temp.setReferenceTemperature(20);
    QCOMPARE(temp.compareTemperature(), false);

    temp.setCurrentTemperature(-2);
    temp.setReferenceTemperature(-1);
    QCOMPARE(temp.compareTemperature(), false);

    temp.setCurrentTemperature(0);
    temp.setReferenceTemperature(-1);
    QCOMPARE(temp.compareTemperature(), true);
}
