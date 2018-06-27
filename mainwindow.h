#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_coffeeButton_clicked();

    void on_cappuccinoButton_clicked();

    void on_espressoButton_clicked();

    void on_cacaoButton_clicked();

    void on_latteMacchiatoButton_clicked();

    void on_hotWaterButton_clicked();

    void on_decreaseMilk_clicked();

    void on_addMilk_clicked();

    void on_decreaseSugar_clicked();

    void on_addSugar_clicked();

    void on_buttonStart_clicked();

    void on_buttonService_clicked();

    void on_buttonBigCup_clicked();

    void on_buttonPlaceCard_clicked();

    void on_buttonAdmin_clicked();

    void on_buttonAdmin_pressed();

    void on_buttonAdmin_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
