// Created by Oleksandra Baga
#ifndef DEFAULTCOFFEEMACHINE_H
#define DEFAULTCOFFEEMACHINE_H
#if defined( USE_DATABASE )


#include "database.h"
#include <string>

class DefaultCoffeeMachine
{
    private:

    public:
        DefaultCoffeeMachine();
        bool createDefaulDB(std::string db_name);
        bool restoreDefaultDB(std::string db_name);
};

extern Database coffeeMachine_DB;
#endif

#endif // DEFAULTCOFFEEMACHINE_H
