#ifndef DECK_H
#define DECK_H

#include <list>
#include "Card.h"

class Deck {
public:
    Deck();

    int deckSize();

//private:
    std::list<Card> cards;
};

#endif // DECK_H
