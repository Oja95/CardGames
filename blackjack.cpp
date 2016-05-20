#include "blackjack.h"
#include "ui_blackjack.h"

BlackJack::BlackJack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlackJack)
{
    ui->setupUi(this);
}

BlackJack::~BlackJack()
{
    delete ui;
}
