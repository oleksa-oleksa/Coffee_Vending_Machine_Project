#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include <QDebug>
#include "databasetest.h"
#include "accounttest.h"


int main(int argc, char *argv[])
{
    // Random Generator Init for Random ID Foo
    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // UNIT TESTS: SEPARATE CLASSES
//    DatabaseTest dbtst01;
//    return QTest::qExec(&dbtst01, argc, argv);

    AccountTest dbtst02;
    return QTest::qExec(&dbtst02, argc, argv);

    return a.exec();
}

