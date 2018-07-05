// Created by Oleksandra Baga
#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "person.h"
#include "bankaccount.h"
#include "account.h"
#include "card.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

    void loadPersonTableWidget();
    void loadBankAccountTableWidget();
    void loadAccountTableWidget();
    void loadCardTableWidget();

    void setAdminControlButtonsStyle();

private slots:


    void on_buttonReloadCardTable_clicked();

    void on_buttonReloadAccountTable_clicked();

    void on_buttonReloadPersonTable_clicked();

    void on_buttonReloadBankAccountTable_clicked();

    void on_buttonAddNewEmployee_clicked();

    void on_buttonSaveNewPerson_clicked();

    void on_buttonEditEmployee_clicked();

    void on_buttonIngredientStatus_clicked();

    void on_buttonCancelNewPerson_clicked();

    void on_buttonSaveNewPerson_pressed();

    void on_buttonCancelNewPerson_released();

    void on_buttonSaveNewPerson_released();

    void on_buttonCancelNewPerson_pressed();

    void on_buttonViewDrinksRecipe_clicked();

private:
    Ui::AdminWindow *ui;

};


#endif // ADMINWINDOW_H
