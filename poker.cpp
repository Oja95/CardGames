#include "poker.h"
#include "ui_poker.h"
#include "blackjack.h"

Poker::Poker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poker)
{
    ui->setupUi(this);

    Card card1 = deck.draw();
    Card card2 = deck.draw();
    Card card3 = deck.draw();
    Card card4 = deck.draw();
    Card card5 = deck.draw();
    ui->label->setPixmap(BlackJack::cardToPixmap(card1));
    ui->label_2->setPixmap(BlackJack::cardToPixmap(card2));
    ui->label_3->setPixmap(BlackJack::cardToPixmap(card3));
    ui->label_4->setPixmap(BlackJack::cardToPixmap(card4));
    ui->label_5->setPixmap(BlackJack::cardToPixmap(card5));
    playerHand.addCard(card1);
    playerHand.addCard(card2);
    playerHand.addCard(card3);
    playerHand.addCard(card4);
    playerHand.addCard(card5);
    Card dealerCard1 = deck.draw();
    Card dealerCard2 = deck.draw();
    Card dealerCard3 = deck.draw();
    Card dealerCard4 = deck.draw();
    Card dealerCard5 = deck.draw();
    ui->label_6->setPixmap(BlackJack::cardToPixmap(dealerCard1));
    ui->label_7->setPixmap(BlackJack::cardToPixmap(dealerCard2));
    ui->label_8->setPixmap(BlackJack::cardToPixmap(dealerCard3));
    ui->label_9->setPixmap(BlackJack::cardToPixmap(dealerCard4));
    ui->label_10->setPixmap(BlackJack::cardToPixmap(dealerCard5));
    dealerHand.addCard(dealerCard1);
    dealerHand.addCard(dealerCard2);
    dealerHand.addCard(dealerCard3);
    dealerHand.addCard(dealerCard4);
    dealerHand.addCard(dealerCard5);
}

Poker::~Poker()
{
    delete ui;
}

void Poker::on_pushButton_clicked()
{
//    ui->pushButton->setDisabled(true);
    if (ui->checkBox->isChecked()) {
        Card newCard = deck.draw();
        playerHand.updateHand(newCard, 0);
        ui->label->setPixmap(BlackJack::cardToPixmap(newCard));
    }
    if (ui->checkBox_2->isChecked()) {
        Card newCard = deck.draw();
        playerHand.updateHand(newCard, 1);
        ui->label_2->setPixmap(BlackJack::cardToPixmap(newCard));
    }
    if (ui->checkBox_3->isChecked()) {
        Card newCard = deck.draw();
        playerHand.updateHand(newCard, 2);
        ui->label_3->setPixmap(BlackJack::cardToPixmap(newCard));
    }
    if (ui->checkBox_4->isChecked()) {
        Card newCard = deck.draw();
        playerHand.updateHand(newCard, 3);
        ui->label_4->setPixmap(BlackJack::cardToPixmap(newCard));
    }
    if (ui->checkBox_5->isChecked()) {
        Card newCard = deck.draw();
        playerHand.updateHand(newCard, 4);
        ui->label_5->setPixmap(BlackJack::cardToPixmap(newCard));
    }
}
