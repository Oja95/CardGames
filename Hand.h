#ifndef HAND_H
#define HAND_H
#include <list>
#include "Card.h"
#include "Deck.h"

class Hand {
public:
    void addCard(Card card);

    void updateHand(Card newCard, int position);

    std::list<Card> getCards();

private:
    std::list<Card> handCards;
};

#endif // HAND_H
