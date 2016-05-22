#include "poker.h"
#include "ui_poker.h"
#include "blackjack.h"
#include <list>
#include <iostream>

Poker::Poker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poker)
{
    ui->setupUi(this);

    // todo: fix this abomination
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
    setPlayerStatus();
    setDealerStatus();

}

Poker::~Poker()
{
    delete ui;
}

void Poker::on_pushButton_clicked()
{
    ui->pushButton->setDisabled(true);
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

    dealerAction();

    setPlayerStatus();
    setDealerStatus();

    if (dealerHandType > playerHandType) {
//        std::cout << "Dealer won!" << std::endl;
        ui->label_18->setText(QString("Dealer won!"));

    } else if (playerHandType > dealerHandType) {
        ui->label_18->setText(QString("You won!"));
//        std::cout << "You won!" << std::endl;
    } else {
        ui->label_18->setText(QString("Same hand type. Comparison not implemented!"));
//        std::cout << "equal types"<< std::endl;
        // todo
    }
}

void Poker::setPlayerStatus() {
    playerHandType = pokerHandEvaluator.evaluate(playerHand);
    switch (playerHandType) {
        case HIGHCARD:
            ui->label_13->setText(QString("High card"));
            break;
        case THREEOFAKIND:
            ui->label_13->setText(QString("Three of a kind"));
            break;
        case FOUROFAKIND:
            ui->label_13->setText(QString("Four of a kind"));
            break;
        case TWOPAIR:
            ui->label_13->setText(QString("Two pairs"));
            break;
        case ONEPAIR:
            ui->label_13->setText(QString("Pair"));
            break;
        case FLUSH:
            ui->label_13->setText(QString("Flush"));
            break;
        case HOUSE:
            ui->label_13->setText(QString("House"));
            break;
        default:
            break;
    }
}

void Poker::setDealerStatus() {
    dealerHandType = pokerHandEvaluator.evaluate(dealerHand);
    switch (dealerHandType) {
        case HIGHCARD:
            ui->label_16->setText(QString("High card"));
            break;
        case THREEOFAKIND:
            ui->label_16->setText(QString("Three of a kind"));
            break;
        case FOUROFAKIND:
            ui->label_16->setText(QString("Four of a kind"));
            break;
        case TWOPAIR:
            ui->label_16->setText(QString("Two pairs"));
            break;
        case ONEPAIR:
            ui->label_16->setText(QString("Pair"));
            break;
        case FLUSH:
            ui->label_16->setText(QString("Flush"));
            break;
        case HOUSE:
            ui->label_16->setText(QString("House"));
            break;
        default:
            break;
    }
}

void Poker::dealerAction() {
    if (dealerHandType == HOUSE) return;
    std::list<Card> dealerCards = dealerHand.getCards();
    Rank cardToHold = NORANK;
    if (dealerHandType == ONEPAIR || dealerHandType == TWOPAIR || dealerHandType == THREEOFAKIND || dealerHandType == FOUROFAKIND) {
        for (std::list<Card>::iterator it = dealerCards.begin(); it != dealerCards.end(); ++it) {
            int rankCount = 0;
            for (std::list<Card>::iterator it2 = dealerCards.begin(); it2 != dealerCards.end(); ++it2) {
                if (it->getRank() == it2->getRank()) rankCount++;
            }
            if (rankCount >= 2) {
                cardToHold = it->getRank();
                break;
            }
        }
    }
    for (int i = 0; i < dealerCards.size(); i++) {
        std::list<Card>::iterator it = dealerCards.begin();
        std::advance(it, i);
        if (it->getRank() != cardToHold) {
            std::cout << "changed card";
            *it = deck.draw();
            dealerHand.updateHand(*it, i);
            switch (i) {
                case 0:
                    ui->label_6->setPixmap(BlackJack::cardToPixmap(*it));
                    break;
                case 1:
                    ui->label_7->setPixmap(BlackJack::cardToPixmap(*it));
                    break;
                case 2:
                    ui->label_8->setPixmap(BlackJack::cardToPixmap(*it));
                    break;
                case 3:
                    ui->label_9->setPixmap(BlackJack::cardToPixmap(*it));
                    break;
                case 4:
                    ui->label_10->setPixmap(BlackJack::cardToPixmap(*it));
                    break;
                default:
                    throw std::string("broke it m8");
                    break;
            }
        }
    }
}
