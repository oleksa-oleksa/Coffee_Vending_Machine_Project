#ifndef INGREDIENTWINDOW_H
#define INGREDIENTWINDOW_H

#include <QDialog>
#include "ingredient.h"

namespace Ui {
class IngredientWindow;
}

class IngredientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IngredientWindow(QWidget *parent = 0);
    ~IngredientWindow();

    void setIngredientLevels(Ingredient *ingredients);
private:
    Ui::IngredientWindow *ui;
};

#endif // INGREDIENTWINDOW_H
