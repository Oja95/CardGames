#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();

    int deckSize();

    void shuffle();

    Card draw();

//private:
    std::vector<Card> cards;
};

#endif // DECK_H
