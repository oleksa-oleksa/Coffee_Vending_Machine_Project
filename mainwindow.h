// Created by Oleksandra Baga
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "card.h"
#include "interactionunit.h"
#include "userchoice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setMainWindowControlButtonsStyle();
    void restartLCD();
    void restartLCDCardEjected();
    void styleMilkProgressBar();
    void styleSugarProgressBar();
    void styleLCDChoiceInformation();
    void styleLCDGreeting();
    void styleInsertButton();
    void styleEjectButton();
    void styleDrinkButtons();
    void styleLCDErrorCard();

    void on_buttonAdmin_clicked();
    void on_buttonCard_clicked();


    void on_buttonLessSugar_clicked();
    void on_buttonMoreSugar_clicked();
    void on_buttonLessMilk_clicked();
    void on_buttonMoreMilk_clicked();
    void on_buttonCoffee_clicked();
    void on_buttonCappuccino_clicked();
    void on_buttonEspresso_clicked();
    void on_buttonLatteMacchiato_clicked();
    void on_buttonCacao_clicked();
    void on_buttonHotwater_clicked();
    // void on_buttonBigPortion_pressed();
    // void on_buttonBigPortion_released();
    void enableControlButtons();
    void disableControlButtons();

    void on_buttonBigPortion_clicked();

private:
    Ui::MainWindow *ui;
};

extern Person *activePerson;
extern Account *activeAccount;
extern Card *card;
extern BankAccount *bankAccount;
extern InteractionUnit iunit;
extern UserChoice *activeUserChoice;

#endif // MAINWINDOW_H
