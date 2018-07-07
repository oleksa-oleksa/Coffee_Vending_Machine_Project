#ifndef SERVICEROUTINE_H
#define SERVICEROUTINE_H
#include "ingredient.h"

#define REFILL_THRESHOLD 0.5

class ServiceRoutine
{

    private:
        bool isCleanedStorageContainer = false;
        bool isCleanedModules = false;
        bool isCleanedGarbageBin = false;


    public:
        ServiceRoutine();
        ~ServiceRoutine();
        void refillOrNot(Ingredient *ingredient);

};

#endif // SERVICEROUTINE_H
