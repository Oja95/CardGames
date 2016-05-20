#include "blackjack.h"
#include "ui_blackjack.h"
#include <QtSvg>
#include <QSvgRenderer>

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

void BlackJack::on_pushButton_clicked()
{
    QImage img = QIcon("/home/tiit/c++/kool/Projekt/CardGames/images/2H.svg").pixmap(QSize(100,100)).toImage();
    QPixmap pixmap = QPixmap::fromImage(img);

    ui->label->setPixmap(pixmap);
}
