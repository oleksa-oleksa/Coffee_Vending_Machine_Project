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

private slots:


private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
