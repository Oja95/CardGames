#include "blackjack.h"
#include "ui_blackjack.h"
#include <QtSvg>
#include <QSvgRenderer>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

BlackJack::BlackJack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlackJack)
{
    ui->setupUi(this);
    on_pushButton_clicked();
    on_pushButton_clicked();
}

BlackJack::~BlackJack()
{
    delete ui;
}

void BlackJack::on_pushButton_clicked()
{
    Card card = deck.draw();
    playerHand.addCard(card);
    checkScore();
    if (blackjackHandEvaluator.evaluate(playerHand) <= 21) {
        dealerDraw();
    }

    QPixmap pixmap = cardToPixmap(card);

    std::cout << blackjackHandEvaluator.evaluate(playerHand) << std::endl;
    ui->label_12->setText(QString::fromStdString(std::to_string(blackjackHandEvaluator.evaluate(playerHand))));

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
    checkScore();
}

QPixmap BlackJack::cardToPixmap(Card card) {
    std::string filename = ":/images/" + card.toString() + ".svg";
    QImage img = QIcon(QString::fromUtf8(filename.c_str())).pixmap(QSize(100,100)).toImage();
    QPixmap pixmap = QPixmap::fromImage(img);
    return pixmap;
}

void BlackJack::checkScore() {
    if (blackjackHandEvaluator.evaluate(playerHand) > 21 || blackjackHandEvaluator.evaluate(dealerHand) > 21) {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        setStatus();
    }
}

void BlackJack::dealerDraw() {
    if (blackjackHandEvaluator.evaluate(dealerHand) < 17 || standing) {
        Card dealerCard = deck.draw();
        dealerHand.addCard(dealerCard);
        QPixmap DealerPixmap = cardToPixmap(dealerCard);
        if (dealerFirst) {
            ui->label_6->setPixmap(DealerPixmap);
            dealerFirst = false;
        } else if (dealerSecond) {
            ui->label_7->setPixmap(DealerPixmap);
            dealerSecond = false;
        } else if (dealerThird) {
            ui->label_8->setPixmap(DealerPixmap);
            dealerThird = false;
        } else if (dealerFourth) {
            ui->label_9->setPixmap(DealerPixmap);
            dealerFourth = false;
        } else {
            ui->label_10->setPixmap(DealerPixmap);
        }
        ui->label_14->setText(QString::fromStdString(std::to_string(blackjackHandEvaluator.evaluate(dealerHand))));
    }
}

void BlackJack::on_pushButton_2_clicked()
{
    standing = true;
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    while (blackjackHandEvaluator.evaluate(dealerHand) <= blackjackHandEvaluator.evaluate(playerHand) && blackjackHandEvaluator.evaluate(dealerHand) != 21
           && blackjackHandEvaluator.evaluate(playerHand) <= 21) {
        dealerDraw();
    }
    setStatus();
}

void BlackJack::setStatus() {
    int playerScore = blackjackHandEvaluator.evaluate(playerHand);
    int dealerScore = blackjackHandEvaluator.evaluate(dealerHand);
    if (dealerScore > 21 && playerScore > 21) {
        ui->label_15->setText(QString("You LOST!"));
    } else if (dealerScore > 21 && playerScore <= 21) {
        ui->label_15->setText(QString("You WIN!"));
    } else if (dealerScore <= 21 && playerScore > 21) {
        ui->label_15->setText(QString("You LOST!"));
    } else if (dealerScore == playerScore) {
        ui->label_15->setText(QString("It's a DRAW!"));
    } else if (dealerScore > playerScore) {
        ui->label_15->setText(QString("You LOST!"));
    } else {
        ui->label_15->setText(QString("You WIN!"));
    }
}
