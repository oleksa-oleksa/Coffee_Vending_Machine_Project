#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"
#include "card.h"

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

    void on_buttonAdmin_clicked();
    void on_buttonAdmin_pressed();
    void on_buttonAdmin_released();

    void on_buttonCard_clicked();

private:
    Ui::MainWindow *ui;
};

extern Person *activePerson;
extern Account *activeAccount;
extern Card *card;


#endif // MAINWINDOW_H
