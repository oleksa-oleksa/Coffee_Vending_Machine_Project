#ifndef SENSOR_H
#define SENSOR_H

class SensorType;

class Sensor
{
public:
    Sensor();
    ~Sensor();
    SensorType getValue();

private:
    SensorType sensor_type;
};

#endif // SENSOR_H
