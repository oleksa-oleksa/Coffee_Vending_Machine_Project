#include "flowmetertest.h"

void FlowmeterTest::testSetRecipeAmountOfLiquid() {

    UserChoice userchoice;
    Flowmeter fm;

    userchoice.setSelectedDrink(COFFEE);
    fm.setRecipeAmountOfLiquid(&userchoice);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 180);

    userchoice.setSelectedDrink(CACAO);
    fm.setRecipeAmountOfLiquid(&userchoice);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 220);

    userchoice.setSelectedDrink(CAPPUCCINO);
    fm.setRecipeAmountOfLiquid(&userchoice);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 220);

    userchoice.setSelectedDrink(ESPRESSO);
    fm.setRecipeAmountOfLiquid(&userchoice);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 100);

    userchoice.setSelectedDrink(HOTWATER);
    fm.setRecipeAmountOfLiquid(&userchoice);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 200);

    userchoice.setSelectedDrink(LATTEMACCHIOTO);
    fm.setRecipeAmountOfLiquid(&userchoice);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 250);

}

void FlowmeterTest::testMainFlowmeterRoutine() {

    Flowmeter fm;
    fm.mainFlowmeterRoutine();

    QCOMPARE(fm.getHasPreparedDrink(), true);
    QCOMPARE(fm.getRecipeAmountOfLiquid(), 0);
}
