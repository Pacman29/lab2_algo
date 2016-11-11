#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "levenshtein_algorithm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString string1 = ui->lineEdit->text();
    QString string2 = ui->lineEdit_2->text();

    int L_res = levenshtein_distance(string1,string2);
    int DL_res = damerau_levenshtein_distance(string1,string2);
    ui->L_result->setText(QString::number(L_res));
    ui->DL_result->setText(QString::number(DL_res));
}
