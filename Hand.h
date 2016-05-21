#ifndef HAND_H
#define HAND_H
#include <list>
#include "Card.h"

class Hand {
public:
    void addCard(Card card);

    std::list<Card> getCards();

private:
    std::list<Card> handCards;
};

#endif // HAND_H
