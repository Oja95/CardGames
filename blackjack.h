#ifndef BLACKJACK_H
#define BLACKJACK_H

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

private:
    Ui::BlackJack *ui;
};

#endif // BLACKJACK_H
