#include <QApplication>
#include <QTest>
#include <QDebug>
#include "databasetest.h"
#include "accounttest.h"
#include "bankaccounttest.h"
#include "cardtest.h"
#include "userchoicetest.h"
#include "interactionunittest.h"
#include "admintest.h"
#include "controlunittest.h"
#include "rfidscannertest.h"
#include "opticalsensortest.h"
#include "serviceroutinetest.h"
#include "ingredienttest.h"
#include "systemtest.h"
#include "flowmetertest.h"
#include "lcdtest.h"
#include "milkmakertest.h"
#include "temperaturesensortest.h"
#include "dc_motortest.h"
#include "integrationtest01.h"
#include "integrationtest02.h"


int main(int argc, char *argv[]) {
    // Random Generator Init for Random ID Foo
    srand(time(NULL));

    QApplication a(argc, argv);

    // SYSTEM TEST
    SystemTest system;
    QTest::qExec(&system, argc, argv);

#if defined(USE_DATABASE)
    // UNIT TESTS: SEPARATE CLASSES
    DatabaseTest dbtst01;
    QTest::qExec(&dbtst01, argc, argv);
#endif

    AccountTest dbtst02;
     QTest::qExec(&dbtst02, argc, argv);

    BankAccountTest dbtst03;
     QTest::qExec(&dbtst03, argc, argv);

    CardTest dbtst04;
     QTest::qExec(&dbtst04, argc, argv);

    UserChoiceTest dbtst05;
     QTest::qExec(&dbtst05, argc, argv);

    InteractionUnitTest dbtst06;
    QTest::qExec(&dbtst06, argc, argv);

    AdminTest dbtst07;
    QTest::qExec(&dbtst07, argc, argv);

    ControlUnitTest dbtst08;
    QTest::qExec(&dbtst08, argc, argv);

    RFIDScannerTest dbtst09;
    QTest::qExec(&dbtst09, argc, argv);

    OpticalSensorTest dbtst10;
    QTest::qExec(&dbtst10, argc, argv);

    ServiceRoutineTest dbtst11;
    QTest::qExec(&dbtst11, argc, argv);

    IngredientTest dbtst12;
    QTest::qExec(&dbtst12, argc, argv);

    FlowmeterTest dbtst13;
    QTest::qExec(&dbtst13, argc, argv);

    LcdTest dbtst14;
    QTest::qExec(&dbtst14, argc, argv);

    MilkmakerTest dbtst15;
    QTest::qExec(&dbtst15, argc, argv);

    TemperatureSensorTest dbtst16;
    QTest::qExec(&dbtst16, argc, argv);

    DC_MotorTest dbtst17;
    QTest::qExec(&dbtst17, argc, argv);

    IntegrationTest01 itest01;
    QTest::qExec(&itest01, argc, argv);

    IntegrationTest02 itest02;
    QTest::qExec(&itest02, argc, argv);


    return 0;

    // return a.exec();
}

