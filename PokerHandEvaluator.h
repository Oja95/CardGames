#ifndef POKERHANDEVALUATOR_H
#define POKERHANDEVALUATOR_H

enum HandType {
    NOTYPE = 0  ,
    HIGHCARD,
    ONEPAIR,
    TWOPAIR,
    THREEOFAKIND,
    STRAIGHT,
    FLUSH,
    HOUSE,
    FOUROFAKIND,
    STRAIGHTFLUSH
};

#include "Hand.h"
#include "Card.h"

class PokerHandEvaluator {
public:
    HandType evaluate(Hand hand);
private:
    bool isFlush();

    Rank hasTriple();

    Rank hasFourOfKind();

    int pairCount();

    bool isStraight();

    std::list<Card> cards;

    Rank getLowest();
};

#endif // POKERHANDEVALUATOR_H
