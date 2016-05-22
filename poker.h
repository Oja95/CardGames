#ifndef POKER_H
#define POKER_H

#include <QDialog>
#include <Hand.h>
#include <Deck.h>
#include <PokerHandEvaluator.h>

namespace Ui {
class Poker;
}

class Poker : public QDialog
{
    Q_OBJECT

public:
    explicit Poker(QWidget *parent = 0);
    ~Poker();
    void setPlayerStatus();
    void setDealerStatus();
    void dealerAction();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Poker *ui;

    Deck deck;
    Hand playerHand;
    Hand dealerHand;
    HandType playerHandType = NOTYPE;
    HandType dealerHandType = NOTYPE;
    PokerHandEvaluator pokerHandEvaluator;
};

#endif // POKER_H
