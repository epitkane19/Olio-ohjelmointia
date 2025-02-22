#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayNumber(int number1Int)
{
    QString number1 = QString::number(number1Int);
    ui->lineEdit->setText(number1);
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;
    if(button) {
        if(button == ui->N1) {
            number1Int = number1.toInt();
            number1Int++;
            number1 = QString::number(number1Int);
            qDebug() << "number1: " << number1Int;
            displayNumber(number1Int);
        }
        else if(button == ui->N2) {
            number1 = "0";
            displayNumber(0);

        }
    }
}
