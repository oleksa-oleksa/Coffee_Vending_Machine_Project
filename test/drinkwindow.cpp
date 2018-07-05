// Created by Oleksandra Baga
#include "drinkwindow.h"
#include "ui_drinkwindow.h"
#include "coffee.h"
#include "cappuccino.h"
#include "espresso.h"
#include "lattemacchiato.h"
#include "cacao.h"
#include "hotwater.h"

DrinkWindow::DrinkWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrinkWindow)
{
    ui->setupUi(this);
    styleCoffee();
    styleCappuccino();
    styleEspresso();
    styleLatte();
    styleCacao();
    styleWater();
}

DrinkWindow::~DrinkWindow()
{
    delete ui;
}


void DrinkWindow::styleCoffee()
{
    Coffee drink;

    QString title = "COFFEE";
    ui->labelCoffeeTitle->setText(title);

    QString sugar = "Sugar: " + QString::number(drink.getSugarAmount());
    QString milk = "Milk: " + QString::number(drink.getMilkAmount());
    QString spec = "Coffee: " + QString::number(drink.getRecipeIngredient());
    QString water = "Water: " + QString::number(drink.getHotWaterAmount());
    ui->labelCoffeeText->setText(sugar + "<br />" + milk + "<br />" + spec + "<br />" + water);
}


void DrinkWindow::styleCappuccino()
{
    Cappuccino drink;

    QString title = "CAPPUCCINO";
    ui->labelCuppTitle->setText(title);

    QString sugar = "Sugar: " + QString::number(drink.getSugarAmount());
    QString milk = "Milk: " + QString::number(drink.getMilkAmount());
    QString spec = "Coffee: " + QString::number(drink.getRecipeIngredient());
    QString water = "Water: " + QString::number(drink.getHotWaterAmount());
    ui->labelCuppText->setText(sugar + "<br />" + milk + "<br />" + spec + "<br />" + water);

}
void DrinkWindow::styleEspresso()
{
    Espresso drink;

    QString title = "ESPRESSO";
    ui->labelEspTitle->setText(title);

    QString sugar = "Sugar: " + QString::number(drink.getSugarAmount());
    QString milk = "Milk: " + QString::number(drink.getMilkAmount());
    QString spec = "Coffee: " + QString::number(drink.getRecipeIngredient());
    QString water = "Water: " + QString::number(drink.getHotWaterAmount());
    ui->labelEsprText->setText(sugar + "<br />" + milk + "<br />" + spec + "<br />" + water);
}
void DrinkWindow::styleLatte()
{
    LatteMacchiato drink;

    QString title = "LATTE MACCHIOTO";
    ui->labelLatTitle->setText(title);

    QString sugar = "Sugar: " + QString::number(drink.getSugarAmount());
    QString milk = "Milk: " + QString::number(drink.getMilkAmount());
    QString spec = "Coffee: " + QString::number(drink.getRecipeIngredient());
    QString water = "Water: " + QString::number(drink.getHotWaterAmount());
    ui->labelLatText->setText(sugar + "<br />" + milk + "<br />" + spec + "<br />" + water);
}
void DrinkWindow::styleCacao()
{
    Cacao drink;

    QString title = "CACAO";
    ui->labelCacaoTitle->setText(title);

    QString sugar = "Sugar: " + QString::number(drink.getSugarAmount());
    QString milk = "Milk: " + QString::number(drink.getMilkAmount());
    QString spec = "Cacao: " + QString::number(drink.getRecipeIngredient());
    QString water = "Water: " + QString::number(drink.getHotWaterAmount());
    ui->labelCacaoText->setText(sugar + "<br />" + milk + "<br />" + spec + "<br />" + water);
}
void DrinkWindow::styleWater()
{
    HotWater drink;

    QString title = "HOTWATER";
    ui->labelWaterTitle->setText(title);

    QString water = "Water: " + QString::number(drink.getHotWaterAmount());
    ui->labelWaterText->setText(water);
}
