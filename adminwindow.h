// Created by Oleksandra Baga
#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>

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

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
