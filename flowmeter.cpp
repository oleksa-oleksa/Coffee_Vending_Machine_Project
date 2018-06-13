#include "flowmeter.h"

Flowmeter::Flowmeter()
{
    sensorType = FLOW;
    sensorState = UNDEFINED;
    flow = 0;
}

Flowmeter::Flowmeter(double setFlow)
{
    sensorType = FLOW;
    sensorState = UNDEFINED;
    flow = setFlow;
}

Flowmeter::~Flowmeter()
{

}

double Flowmeter::getFlow()
{
    return this->flow;
}
