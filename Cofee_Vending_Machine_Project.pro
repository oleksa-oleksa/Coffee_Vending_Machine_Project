#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T23:58:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cofee_Vending_Machine_Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    userchoice.cpp \
    interactionunit.cpp \
    indicationunit.cpp \
    card.cpp \
    account.cpp \
    accountstatus.cpp \
    bankaccount.cpp \
    dataset.cpp \
    admin.cpp \
    drink.cpp \
    ingredient.cpp \
    person.cpp \
    serviceroutine.cpp

HEADERS += \
        mainwindow.h \
    userchoice.h \
    interactionunit.h \
    indicationunit.h \
    card.h \
    account.h \
    accountstatus.h \
    bankaccount.h \
    dataset.h \
    admin.h \
    cacao.h \
    cappuccino.h \
    coffee.h \
    drink.h \
    drinktype.h \
    espresso.h \
    hotwater.h \
    ingredient.h \
    lattemacchiato.h \
    person.h \
    serviceroutine.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    Cofee_Vending_Machine_Project.pro.user
