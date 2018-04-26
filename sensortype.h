#ifndef SENSORTYPE_H
#define SENSORTYPE_H


class SensorType
{
public:
    SensorType();
    ~SensorType();

private:
    enum{
        RFID,
        OPTICAL,
        PRESSURE,
        TEMPERATURE,
        FLOW,
        BUTTON,
        BRIGHTNESS,
        PROXIMITY
    };
};

#endif // SENSORTYPE_H
