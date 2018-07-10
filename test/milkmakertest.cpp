#include "milkmakertest.h"

void MilkmakerTest::testMakeMilkFoom() {

    Milkmaker milkmaker;

    milkmaker.makeMilkFoam(COFFEE);
    milkmaker.makeMilkFoam(LATTEMACCHIOTO);
    milkmaker.makeMilkFoam(CAPPUCCINO);
    milkmaker.makeMilkFoam(HOTWATER);
}
