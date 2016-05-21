#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blackjack.h"
#include <iostream>

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


void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    blackjackWindow = new BlackJack();
    blackjackWindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    pokerWindow = new Poker();
    pokerWindow->show();
}
