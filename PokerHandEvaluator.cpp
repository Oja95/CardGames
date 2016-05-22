#include "PokerHandEvaluator.h"
#include "Card.h"

HandType PokerHandEvaluator::evaluate(Hand hand) {
    cards = hand.getCards();
    if (isFlush()) {
        return FLUSH;
    }
    if (hasFourOfKind() != NORANK) {
        return FOUROFAKIND;
    }
    if (hasTriple() != NORANK && pairCount() >= 2) {
        return HOUSE;
    }
    if (hasTriple() != NORANK) {
        return THREEOFAKIND;
    }
    if (pairCount() == 2) {
        return TWOPAIR;
    }
    if (pairCount() == 1) {
        return ONEPAIR;
    }


    return HIGHCARD;
}

bool PokerHandEvaluator::isFlush() {
    Suit suit = cards.back().getSuit();
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        if (it->getSuit() != suit) return false;
    }
    return true;
}

Rank PokerHandEvaluator::hasTriple() {
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        Rank cardRank = it->getRank();
        int sameCount = 0;
        for (std::list<Card>::iterator it2 = cards.begin(); it2 != cards.end(); ++it2) {
            if (it2->getRank() == cardRank) sameCount++;
        }
        if (sameCount == 3) return cardRank;
    }
    return Rank::NORANK;
}

Rank PokerHandEvaluator::hasFourOfKind() {
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        Rank cardRank = it->getRank();
        int sameCount = 0;
        for (std::list<Card>::iterator it2 = cards.begin(); it2 != cards.end(); ++it2) {
            if (it2->getRank() == cardRank) sameCount++;
        }
        if (sameCount == 4) return cardRank;
    }
    return Rank::NORANK;
}

int PokerHandEvaluator::pairCount() {
    int pairCount = 0;
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        Rank cardRank = it->getRank();
        int sameCount = 0;
        for (std::list<Card>::iterator it2 = cards.begin(); it2 != cards.end(); ++it2) {
            if (it2->getRank() == cardRank) sameCount++;
        }
        if (sameCount >= 2) pairCount++;
    }
    return pairCount / 2;
}

bool PokerHandEvaluator::isStraight() {
    if (pairCount() > 0) return false;
    Rank lowest = getLowest();
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        Rank cardRank = it->getRank();
        for (std::list<Card>::iterator it2 = cards.begin(); it2 != cards.end(); ++it2) {

        }
    }
}

Rank PokerHandEvaluator::getLowest() {
    Rank lowest = NORANK;
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        if (it->getRank() < NORANK) lowest = it->getRank();
    }
    return lowest;
}
