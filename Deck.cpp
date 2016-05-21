#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <iostream>

Deck::Deck() {
    for (int i = ACE; i != NORANK; i++) {
        for (int j = SPADE; j != NOSUIT; j++) {
            cards.push_back(Card(static_cast<Suit>(j), static_cast<Rank>(i)));
        }
    }
    shuffle();
}

int Deck::deckSize() {
    return cards.size();
}

void Deck::shuffle() {
    // todo: figure out actual random shuffle
    random_shuffle(cards.begin(), cards.end());
}

Card Deck::draw() {
    // its not like we're gonna run out of cards whilst a game of blackjack
    Card card = cards.back();
    cards.pop_back();
    std::cout << card.toString() << std::endl;
    return card;
}
