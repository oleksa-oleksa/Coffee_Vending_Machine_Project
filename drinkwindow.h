// Created by Oleksandra Baga

// Window for drink recipies
// No interaction with admin, simple design window
// additional application feature
#ifndef DRINKWINDOW_H
#define DRINKWINDOW_H

#include <QDialog>

namespace Ui {
class DrinkWindow;
}

class DrinkWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DrinkWindow(QWidget *parent = 0);
    ~DrinkWindow();

    void styleCoffee();
    void styleCappuccino();
    void styleEspresso();
    void styleLatte();
    void styleCacao();
    void styleWater();



private:
    Ui::DrinkWindow *ui;
};

#endif // DRINKWINDOW_H
