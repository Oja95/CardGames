#ifndef POKER_H
#define POKER_H

#include <QDialog>

namespace Ui {
class Poker;
}

class Poker : public QDialog
{
    Q_OBJECT

public:
    explicit Poker(QWidget *parent = 0);
    ~Poker();

private:
    Ui::Poker *ui;
};

#endif // POKER_H
