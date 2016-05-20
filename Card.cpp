#include <Card.h>

Card::Card(Suit suit, Rank rank) {
    this->suit = suit;
    this->rank = rank;
}

Rank Card::getRank() {
    return this->rank;
}

Suit Card::getSuit() {
    return this->suit;
}

std::string Card::rankValue() {
    switch (this->rank) {
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "J";
        case QUEEN: return "Q";
        case KING: return "K";
        case ACE: return "A";
        default:
            // This can't happen
            throw std::string("Broke card class with null rank!");
    }
}

std::string Card::suitValue() {
    switch (this->suit) {
        case SPADE: return "S";
        case HEART: return "H";
        case CLUB: return "C";
        case DIAMOND: return "D";
        default:
            // This can't happen
            throw std::string("Broke card class with null rank!");
    }
}


std::string Card::toString() {
    return Card::rankValue() + Card::suitValue();
}
