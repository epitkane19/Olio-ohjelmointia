#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startClickHandler);

    connect(ui->stop, &QPushButton::clicked, this, &MainWindow::stopClickHandler);

    connect(ui->switchL, &QPushButton::clicked, this, &MainWindow::switchToP2);
    connect(ui->switchR, &QPushButton::clicked, this, &MainWindow::switchToP1);

    connect(ui->timer120, &QPushButton::clicked, this, &MainWindow::timerClickHandler);
    connect(ui->timer5, &QPushButton::clicked, this, &MainWindow::timerClickHandler);

}

MainWindow::~MainWindow()
{
    if(timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
    delete ui;
}

void MainWindow::startClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;
    setGameInfoText("Game ongoing", 30);

    p1Time = gameTime;
    p2Time = gameTime;
    currentPlayer = 1;

    ui->player1Time->setRange(0,gameTime);
    ui->player2Time->setRange(0,gameTime);
    ui->player1Time->setValue(gameTime);
    ui->player2Time->setValue(gameTime);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    timer->setInterval(1000);
    timer->start();


}

void MainWindow::switchToP2()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;

    currentPlayer = 2;
}

void MainWindow::switchToP1()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;

    currentPlayer = 1;
}

void MainWindow::timerClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;
    setGameInfoText("Ready to play", 30);

    if(button == ui->timer120) {
        gameTime = 120;
    }
    else if(button == ui->timer5) {
        gameTime = 300;
    }
}

void MainWindow::updateProgressBar()
{
    if(currentPlayer == 1) {
        p1Time = p1Time - 1;
        ui->player1Time->setValue(p1Time);
    }
    else if(currentPlayer == 2) {
        p2Time = p2Time - 1;
        ui->player2Time->setValue(p2Time);
    }

    if(p1Time == 0) {
        setGameInfoText("Player 2 WON!!!", 30);
    }
    else if(p2Time == 0) {
        setGameInfoText("Player 1 WON!!!", 30);
    }
}

void MainWindow::setGameInfoText(QString t, short s)
{
    QString text = t;
    short size = s;

    ui->label->setText(text);
    ui->label->setFont(QFont(ui->label->font().family(), size));
}

void MainWindow::stopClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;
    setGameInfoText("New game via START button", 30);

    if(timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }

}
