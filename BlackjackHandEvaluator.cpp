#include "BlackjackHandEvaluator.h"
#include <list>

int BlackjackHandEvaluator::evaluate(Hand hand) {
    std::list<Card> cards = hand.getCards();
    int value = 0;
    int aceCount = 0;
    for (std::list<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        if (it->getRank() == ACE) {
            aceCount++;
            continue;
        } else {
            value += cardRankToInt(*it);
        }
    }    
    while (aceCount--) {
        if (value + 11 <= 21) {
            value += 11;
        } else {
            value++;
        }
    }
    return value;
}

int BlackjackHandEvaluator::cardRankToInt(Card card) {
    switch (card.getRank()) {
    case TWO: return 2;
    case THREE: return 3;
    case FOUR: return 4;
    case FIVE: return 5;
    case SIX: return 6;
    case SEVEN: return 7;
    case EIGHT: return 8;
    case NINE: return 9;
    case TEN: return 10;
    case JACK: return 10;
    case QUEEN: return 10;
    case KING: return 10;
    case ACE: return 11;
    default:
        return 0;
    }
}
