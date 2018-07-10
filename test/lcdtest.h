#ifndef LCDTEST_H
#define LCDTEST_H

#include <QtTest/QtTest>
#include <QString>
#include <QObject>
#include "lcd_display.h"
#include "userchoice.h"

class LcdTest : public QObject
{
    Q_OBJECT
    private slots:
        void testWriteDefaultText();
        void testWriteGreetingText();
        void testWriteUserChoiceText();
        void testSystemErrorMessage();

};

#endif // LCDTEST_H
