#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Deck.h"
#include "Hand.h"
#include "BlackjackHandEvaluator.h"
#include "Card.h"
#include <QDialog>

namespace Ui {
class BlackJack;
}

class BlackJack : public QDialog
{
    Q_OBJECT

public:
    explicit BlackJack(QWidget *parent = 0);
    ~BlackJack();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BlackJack *ui;

    int initialLabelPosition = 10;

    bool first = true;
    bool second = true;
    bool third = true;
    bool fourth = true;

    Deck deck;
    Hand playerHand;
    Hand dealerHand;
};

#endif // BLACKJACK_H
