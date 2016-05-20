#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    for (int i = ACE; i != NORANK; i++) {
        for (int j = SPADE; j != NOSUIT; j++) {
            cards.push_back(Card(static_cast<Suit>(j), static_cast<Rank>(i)));
        }
    }
}

int Deck::deckSize() {
    return cards.size();
}
