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
    void displayResult(float result);

private:
    Ui::MainWindow *ui;
    QString number1, number2;
    //int state;
    float result;
    char operand;
    bool switchDisplay;

    void numberClickedHandler();
    void clearAndEnterClickHandler();
    void addSubMulDivClickHandler();
    void resetLineEdits();

    //Tein operand homman hieman eritavalla joten int state; jäi turhaksi itsellä.
};
#endif // MAINWINDOW_H
