#ifndef SERVICEROUTINE_H
#define SERVICEROUTINE_H
#include "ingredient.h"

#define REFILL_THRESHOLD 0.5

class ServiceRoutine
{

    private:

    public:
        ServiceRoutine();
        ~ServiceRoutine();
        void refillOrNot(Ingredient *ingredient);

};

#endif // SERVICEROUTINE_H
