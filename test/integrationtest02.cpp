#include "integrationtest02.h"
#include "mainwindow.h"
#include "controlunit.h"

void IntegrationTest02::cleanup()
{
    Person::AllEmployee.clear();
    BankAccount::AllBankAccounts.clear();
    Account::AllAccounts.clear();
    Card::AllCards.clear();
}

void IntegrationTest02::testMachineSetup()
{
    Account::AllAccounts.push_back(Account());
    BankAccount::AllBankAccounts.push_back(BankAccount());
    Person::AllEmployee.push_back(Person());
    Card::AllCards.push_back(Card());

    Account &a = Account::AllAccounts[0];
    BankAccount &ba = BankAccount::AllBankAccounts[0];
    Person &p = Person::AllEmployee[0];
    Card &c = Card::AllCards[0];

    activeUserChoice = NULL;
    a.setOwner(&p);
    a.setBankAccount(&ba);
    a.setOwner(&p);
    ba.setAccount(&a);
    c.setAccount(&a);

    MainWindow mw(NULL);

    // Assert configuration of global state
    QCOMPARE(activeAccount, &a);
    QCOMPARE(activePerson, &p);
    QCOMPARE(bankAccount, &ba);
    QCOMPARE(activeUserChoice->getCard(), &c);


    // Assert all buttons are connected to interaction unit
    QVERIFY(iunit.getMoreSugar());
    QVERIFY(iunit.getLessSugar());
    QVERIFY(iunit.getMoreMilk());
    QVERIFY(iunit.getMoreMilk());
    QVERIFY(iunit.getLessMilk());
    QVERIFY(iunit.getCoffee());
    QVERIFY(iunit.getCappuccino());
    QVERIFY(iunit.getEspresso());
    QVERIFY(iunit.getLatteMacchiato());
    QVERIFY(iunit.getCacao());
    QVERIFY(iunit.getHotWater());
    QVERIFY(iunit.getBigPortion());
    QVERIFY(iunit.getStart());

    // Hardware getters
    QVERIFY(control.getIngredients());

    QVERIFY(control.getCardScanner());
    QVERIFY(control.getFlowmeter());
    QVERIFY(control.getOpticalSensor());
    QVERIFY(control.getTemperatureSensor());
    QVERIFY(control.getBrightSensor());

    QVERIFY(control.getDisplay());
    QVERIFY(control.getHeater());
    QVERIFY(control.getMilkMaker());

    for (int i = 0; i<MOTOR_TYPES_NUMBER; i++)
        QVERIFY(control.getMotor((MotorType)i));

    QCOMPARE(control.getDisplay()->getTitle(), "Please insert card");

}
