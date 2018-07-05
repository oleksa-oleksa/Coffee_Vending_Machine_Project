#include <QApplication>
#include <QTest>
#include <QDebug>
#include "databasetest.h"
#include "accounttest.h"
#include "bankaccounttest.h"
#include "cardtest.h"
#include "userchoicetest.h"
#include "interactionunittest.h"
#include "admin.h"
#include "controlunit.h"


int main(int argc, char *argv[])
{
    // Random Generator Init for Random ID Foo
    srand(time(NULL));

    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // UNIT TESTS: SEPARATE CLASSES
    // ACTIVATE ONLY ONE TEST CALL
    DatabaseTest dbtst01;
    QTest::qExec(&dbtst01, argc, argv);

    AccountTest dbtst02;
     QTest::qExec(&dbtst02, argc, argv);

    BankAccountTest dbtst03;
     QTest::qExec(&dbtst03, argc, argv);

    CardTest dbtst04;
     QTest::qExec(&dbtst04, argc, argv);

    UserChoiceTest dbtst05;
     QTest::qExec(&dbtst05, argc, argv);

    InteractionUnitTest dbtst06;
    return QTest::qExec(&dbtst06, argc, argv);

    // return a.exec();
}

