#ifndef BLACKJACKHANDEVALUATOR_H
#define BLACKJACKHANDEVALUATOR_H
#include <list>
#include "Hand.h"

class BlackjackHandEvaluator {
public:
    
    int evaluate(Hand hand);
    
private:
    int cardValue = 0;

    int cardRankToInt(Card card);
    
};

#endif // BLACKJACKHANDEVALUATOR_H
