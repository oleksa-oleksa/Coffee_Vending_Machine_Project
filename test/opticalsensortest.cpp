#include "opticalsensortest.h"

void OpticalSensorTest::testGetOpticalSensorsMeasurement() {
    //Test1
    Flowmeter fm1;

    OpticalSensor opSensor1(&fm1);
    QCOMPARE(opSensor1.getOpticalFlowSensorsMeasurements(), NO_CUP);

    //Test2
    Flowmeter fm2;
    fm2.mainFlowmeterRoutine(); // setHasPrepared = True
    OpticalSensor opSensor2(&fm2);
    opSensor2.setDistanceToObject(4); // isObjectdetected = true
    QCOMPARE(opSensor2.getOpticalFlowSensorsMeasurements(), FULL_CUP);

    //Test3
    Flowmeter fm3; // setHasPrepared = false
    OpticalSensor opSensor3(&fm3);
    opSensor3.setDistanceToObject(4); // isObjectdetected = true
    QCOMPARE(opSensor3.getOpticalFlowSensorsMeasurements(), EMPTY_CUP);
}
