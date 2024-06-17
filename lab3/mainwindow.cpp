#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <string>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    int sum, initialPayment,years,percent, percentAcc;
    double monthlyPayment;
    sum = ui->sumInput->property("text").toInt();
    initialPayment = ui->initialinput->property("text").toInt();
    years =ui->yearsInput->property("text").toInt();
    percent = ui->percentInput->property("text").toInt();
    double mothlyPercent = 1.0*percent/(12* 100);
    monthlyPayment = ((sum - initialPayment) * mothlyPercent)/(1 - pow(1+mothlyPercent,years * -12));
    monthlyPayment = round(monthlyPayment);
    ui->payment_res->setText(QString::number(monthlyPayment));
    ui->percentRes->setText(QString::number(monthlyPayment * years * 12 - sum));

}

