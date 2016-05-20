#ifndef CARD_H
#define CARD_H
#include <string>

enum Suit {
    SPADE,
    HEART,
    DIAMOND,
    CLUB
};

enum Rank {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card {
public:
    Card(Suit suit, Rank rank);

    std::string rankValue();

    std::string suitValue();

    std::string toString();

    Rank getRank();

    Suit getSuit();

private:
    Suit suit;
    Rank rank;
};

#endif // CARD_H
