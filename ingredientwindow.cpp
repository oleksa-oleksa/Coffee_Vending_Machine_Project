#include "ingredientwindow.h"
#include "ui_ingredientwindow.h"

IngredientWindow::IngredientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngredientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Vending Machine Tanks");
}

IngredientWindow::~IngredientWindow()
{
    delete ui;
}

void IngredientWindow::setIngredientLevels(Ingredient *ingredients)
{
    ui->progressBarCacao->setMaximum(CACAO_TANK_AMOUNT);
    ui->progressBarCoffee->setMaximum(COFFEE_TANK_AMOUNT);
    ui->progressBarMilk->setMaximum(MILK_TANK_AMOUNT);
    ui->progressBarSugar->setMaximum(SUGAR_TANK_AMOUNT);


    ui->progressBarCacao->setValue(ingredients->getCacaoIngredient());
    ui->progressBarCoffee->setValue(ingredients->getCoffeeIngredient());
    ui->progressBarMilk->setValue(ingredients->getMilkIngredient());
    ui->progressBarSugar->setValue(ingredients->getSugarIngredient());

    ui->labelCacaoAmount->setText(QString::number(ingredients->getCacaoIngredient()));
    ui->labelCoffeeAmount->setText(QString::number(ingredients->getCoffeeIngredient()));
    ui->labelMilkAmount->setText(QString::number(ingredients->getMilkIngredient()));
    ui->labelSugarAmount->setText(QString::number(ingredients->getSugarIngredient()));

}
