#include "Hand.h"

void Hand::addCard(Card card) {
    handCards.push_back(card);
}

std::list<Card> Hand::getCards() {
    return handCards;
}
