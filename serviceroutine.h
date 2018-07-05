#ifndef SERVICEROUTINE_H
#define SERVICEROUTINE_H
#include "ingredient.h"


class ServiceRoutine
{

    private:
        bool isCleanedStorageContainer = false;
        bool isCleanedModules = false;
        bool isCleanedGarbageBin = false;
        Ingredient *tankIngredient;


    public:
        ServiceRoutine();
        ~ServiceRoutine();


};

#endif // SERVICEROUTINE_H
