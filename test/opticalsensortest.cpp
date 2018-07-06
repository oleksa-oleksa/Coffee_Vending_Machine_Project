#include "opticalsensortest.h"

void OpticalSensorTest::testGetOpticalSensorsMeasurement()
{
    //Test1
    OpticalSensor opSensor1;
    QCOMPARE(opSensor1.getOpticalFlowSensorsMeasurements(), NO_CUP);

    //Test2
    Flowmeter *fm1 = new Flowmeter();
    fm1->mainFlowmeterRoutine(); // setHasPrepared = True
    OpticalSensor opSensor2(fm1);
    opSensor2.setDistanceToObject(4); // isObjectdetected = true
    QCOMPARE(opSensor2.getOpticalFlowSensorsMeasurements(), FULL_CUP);

    //Test3
    Flowmeter fm2; // setHasPrepared = false
    OpticalSensor opSensor3(&fm2);
    opSensor3.setDistanceToObject(4); // isObjectdetected = true
    QCOMPARE(opSensor3.getOpticalFlowSensorsMeasurements(), EMPTY_CUP);
}
