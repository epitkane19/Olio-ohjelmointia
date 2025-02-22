#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayResult(float result)
{
    QString calc = QString::number(result);
    ui->result->setText(calc);
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    QString number = name.last(1);
    qDebug() << "Button name: " << name;
    qDebug() << "Button number: " << number;
    if(switchDisplay) {
        ui->num1->setText(ui->num1->text() + number);
    }
    else {
        ui->num2->setText(ui->num2->text() + number);
    }
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;
    if(button) {
        if(button == ui->enter) {
            qDebug() << "Operand name: " << operand;
            float number1 = ui->num1->text().toFloat();
            float number2 = ui->num2->text().toFloat();
            switch (operand) {
                case 'a':

                    result = number1 + number2;
                    displayResult(result);
                    break;

                case 's':

                    result = number1 - number2;
                    displayResult(result);
                    break;

                case 'm':

                    result = number1 * number2;
                    displayResult(result);
                    break;

                case 'd':

                    if (number2 != 0) {
                        result = number1 / number2;
                        displayResult(result);
                    } else {
                        ui->result->setText("Error");
                    }

                    break;

                default:
                    qDebug() << "Error!";
            }
        }
        else if(button == ui->clear) {
            qDebug() << "Operand name: " << operand;
            ui->num1->setText("");
            ui->num2->setText("");
            ui->result->setText("");
            switchDisplay = true;
        }
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString op = button->objectName().first(1);
    operand = op.at(0).toLatin1();
    switchDisplay = false;
}
