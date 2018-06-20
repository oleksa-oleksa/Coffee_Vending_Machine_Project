#include "mainwindow.h"
#include <QApplication>
#include <QTest>
#include <QDebug>
#include "databasetest.h"


int main(int argc, char *argv[])
{
    // Random Generator Init for Random ID Foo
    srand(time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // TESTS
    DatabaseTest dbtst;
    return QTest::qExec(&dbtst, argc, argv);

    return a.exec();
}

