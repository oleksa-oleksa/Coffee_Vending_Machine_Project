#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include <QDebug>
#include "databasetest.h"
#include "accounttest.h"
#include "bankaccounttest.h"
#include "cardtest.h"
#include "userchoicetest.h"
#include "interactionunittest.h"

int main(int argc, char *argv[])
{
    // Random Generator Init for Random ID Foo
    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // UNIT TESTS: SEPARATE CLASSES
    // ACTIVATE ONLY ONE TEST CALL

//    DatabaseTest dbtst01;
//    return QTest::qExec(&dbtst01, argc, argv);

//    AccountTest dbtst02;
//    return QTest::qExec(&dbtst02, argc, argv);

//    BankAccountTest dbtst03;
//    return QTest::qExec(&dbtst03, argc, argv);

//    CardTest dbtst04;
//    return QTest::qExec(&dbtst04, argc, argv);

//    UserChoiceTest dbtst05;
//    return QTest::qExec(&dbtst05, argc, argv);

//    InteractionUnitTest dbtst06;
//    return QTest::qExec(&dbtst06, argc, argv);

    return a.exec();
}

