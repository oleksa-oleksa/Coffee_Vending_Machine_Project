// Exisiting file implemented for project by Oleksandra Baga
#ifndef FLOWMETER_H
#define FLOWMETER_H
#include "sensor.h"
#include "userchoice.h"


class Flowmeter : public Sensor
{
    private:
        int recipeAmountOfLiquid;
        bool hasPreparedDrink;

    public:
        Flowmeter();
        virtual ~Flowmeter();

        int getRecipeAmountOfLiquid();
        void setRecipeAmountOfLiquid(UserChoice *activeUserChoice);
        bool mainFlowmeterRoutine();
        bool getHasPreparedDrink();

};

#endif // FLOWMETER_H
