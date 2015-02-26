#include "BlackjackHand.h"
#include "Card.h"
#include <iostream>
using namespace std;

void BlackjackHand::setValue() // Setting the value of a blackjack hand
// Must avoid becoming bust if possible.
{
    int handScore = 0;
    for(int i = 0; i < Hand.size(); i++)
        if(Hand[i].getDenomination()!= Hand[i].ACE || handScore + Hand[i].getValue() <= BUST )
           handScore += Hand[i].getValue();
         else
         // score aces low -- if would be bust -- add 1.
         handScore++;

     value = handScore;

}

void BlackjackHand::displayHand()const
{
   std::cout << std::endl;
   std::cout << "The hand is\n";
   for(int i = 0; i < Hand.size(); i++)
       std::cout << std::endl << Hand[i].getString();
}


