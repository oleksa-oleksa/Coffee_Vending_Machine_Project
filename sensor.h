#ifndef SENSOR_H
#define SENSOR_H
<<<<<<< HEAD
=======

#include <string>
>>>>>>> b29e107393a341e8ed723a49fcea80dd74fe9793
#include "sensortype.h"
#include "state.h"

class Sensor
{
    SensorType sensor_type;

    public:
        Sensor();
        SensorType getValue() const;
        SensorType getSensorType() const;
        bool getSensorState() const;
<<<<<<< HEAD
        void setSensorType(String type);
        void setSensorstate(enum State state);
=======
        void setSensorType(std::string type);
        void setSensorstate(State state);

    private:
        SensorType sensor_type;
>>>>>>> b29e107393a341e8ed723a49fcea80dd74fe9793
};

#endif // SENSOR_H
