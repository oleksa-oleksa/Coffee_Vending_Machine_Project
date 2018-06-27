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

    void on_buttonAdmin_clicked();

    void on_buttonAdmin_pressed();

    void on_buttonAdmin_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
