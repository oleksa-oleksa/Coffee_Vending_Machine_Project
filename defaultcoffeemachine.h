// Created by Oleksandra Baga
#ifndef DEFAULTCOFFEEMACHINE_H
#define DEFAULTCOFFEEMACHINE_H

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

#endif // DEFAULTCOFFEEMACHINE_H
