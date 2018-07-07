// Created by Oleksandra Baga
#include "milkmaker.h"
#include "actuator.h"
#include "QDebug"

Milkmaker::Milkmaker()
{
    //actuator_duration =
    actuatorType = MILKMAKER;
    actuatorState = UNDEFINED;
}

Milkmaker::~Milkmaker()
{

}

void Milkmaker::makeMilkFoam(DrinkType drink) {
    if (drink == CAPPUCCINO) {
        qDebug() << "MILK MAKER: Ideal Milk Foam for Cappucino is made";
    }
    else if (drink == LATTEMACCHIOTO) {
        qDebug() << "MILK MAKER: Ideal Milk Foam for Latte Macchioto is made";
    }
    else {
        qDebug() << "MILK MAKER: This drink doesn't require making a foam!";

    }
}















