#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void timeOut();

private:
    Ui::MainWindow *ui;
    short p1Time;
    short p2Time;
    short gameTime;
    QTimer *timer = nullptr;
    short currentPlayer = 1;

    void startClickHandler();
    void switchToP2();
    void switchToP1();
    void timerClickHandler();

    void updateProgressBar();
    void setGameInfoText(QString t, short s);

    void stopClickHandler();
};
#endif // MAINWINDOW_H
