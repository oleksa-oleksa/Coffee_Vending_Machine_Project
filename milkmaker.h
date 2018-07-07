// Created by Oleksandra Baga
#ifndef MILKMAKER_H
#define MILKMAKER_H
#include "actuator.h"
#include <string>
#include "drinktype.h"
using namespace std;

class Milkmaker : public Actuator
{
    public:
        Milkmaker();
        virtual ~Milkmaker();
        void makeMilkFoam(DrinkType drink);
};

#endif // MILKMAKER_H
