#include "poker.h"
#include "ui_poker.h"

Poker::Poker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poker)
{
    ui->setupUi(this);
}

Poker::~Poker()
{
    delete ui;
}
