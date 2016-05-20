#ifndef CARD_H
#define CARD_H
#include <string>

enum Suit {
    SPADE,
    HEART,
    DIAMOND,
    CLUB,
    NOSUIT
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
    KING,
    NORANK
};

class Card {
public:
    Card(Suit suit, Rank rank);

    std::string toString();

    Rank getRank();

    Suit getSuit();

private:
    Suit suit;

    Rank rank;

    std::string rankValue();

    std::string suitValue();
};

#endif // CARD_H
