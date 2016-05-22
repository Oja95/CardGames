#include <iterator>
#include <iostream>
#include "Hand.h"
#include <algorithm>

void Hand::addCard(Card card) {
    handCards.push_back(card);
}

std::list<Card> Hand::getCards() {
    return handCards;
}

void Hand::updateHand(Card newCard, int position) {
    std::list<Card>::iterator it = handCards.begin();
    std::advance(it, position);
    std::cout << it->toString() << std::endl;
    *it = newCard;
}
