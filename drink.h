#ifndef DRINK_H
#define DRINK_H

#include "userchoice.h"
#include "opticalsensor.h"
#include "proximitysensor.h"
#include "dc_motor.h"
#include "temperatursensor.h"
#include "waterheater.h"
#include "flowmeter.h"
#include "brewgroup.h"
#include "milkmaker.h"
#include "rfid_scanner.h"

class Drink
{
    protected:

    int sugarAmount;
    int milkAmount;
    int hotWaterAmount;
    int recipeTemperature;
    double price;

    Drink();

   public:
//      Drink(int sugar, int milk, int coffee,
//            int cacao, int water, int temp, double p);
      Drink(int sugarAmount,
            int milkAmount,
            int hotWaterAmount,
            int recipeTemperature,
            double price);

      int getSugarAmount();
      int getMilkAmount();
      double getPrice();
};


extern Drink DrinkRecipes[];

#endif
