#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayNumber(int value);


private:
    Ui::MainWindow *ui;
    QString number1;
    int number1Int = 0;
    //float result;

    void numberClickedHandler();
    void countClickHandler();
    void resetLineEdits();
};
#endif // MAINWINDOW_H
