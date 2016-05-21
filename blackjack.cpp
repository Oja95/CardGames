#include "blackjack.h"
#include "ui_blackjack.h"
#include <QtSvg>
#include <QSvgRenderer>
#include <string>

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
    Card card = deck.draw();
    playerHand.addCard(card);
    std::string filename = ":/images/" + card.toString() + ".svg";
    QImage img = QIcon(QString::fromUtf8(filename.c_str())).pixmap(QSize(100,100)).toImage();
    QPixmap pixmap = QPixmap::fromImage(img);

    if (first) {
        ui->label->setPixmap(pixmap);
        first = false;
    } else if (second) {
        ui->label_2->setPixmap(pixmap);
        second = false;
    } else if (third) {
        ui->label_3->setPixmap(pixmap);
        third = false;
    } else if (fourth) {
        ui->label_4->setPixmap(pixmap);
        fourth = false;
    } else {
        ui->label_5->setPixmap(pixmap);
    }
}

void BlackJack::on_pushButton_2_clicked()
{

}
