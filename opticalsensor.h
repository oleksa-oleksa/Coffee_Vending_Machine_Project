// Exisiting file implemented for project by Oleksandra Baga
#ifndef OPTICALSENSOR_H
#define OPTICALSENSOR_H
#include "sensor.h"
#include "flowmeter.h"

#define OPTICAL_DISTANCE 5

enum CupHolderState
{
    NO_CUP,
    EMPTY_CUP,
    FULL_CUP
};


class OpticalSensor : public Sensor
{
    private:
        bool isObjectDetected;
        int distanceToObject;
        Flowmeter *flow;

    public:
        OpticalSensor();
        OpticalSensor(Flowmeter *flow);
        OpticalSensor(bool);
        ~OpticalSensor();

        bool getOpticalValue();
        int getDistanceToObject();
        void setDistanceToObject(int distanceToObject);
        CupHolderState getOpticalFlowSensorsMeasurements();
};

#endif // OPTICALSENSOR_H
