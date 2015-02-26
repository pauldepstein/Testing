#ifndef BLACKJACKHAND_H_INCLUDED
#define BLACKJACKHAND_H_INCLUDED
// Representing a blackjack hand
#include "Card.h"
#include <vector>
class BlackjackHand{
std::vector<Card> Hand; // hand
int value; // value of hand
void setValue(); // Add up the values of the vector of cards.
static const int BUST = 21; // bust if over this value
bool busted; // bust if over 21.

public:
double getValue()const{return value;}
BlackjackHand() {};
// Displaying the cards in the hand
void displayHand()const;
// Drawing another card
BlackjackHand draw(Card card){
                               Hand.push_back(card);
                               return BlackjackHand(Hand);}
BlackjackHand(std::vector<Card> hand){
                                      Hand = hand;
                                      setValue();
                                      busted = value > BUST;
                                      if(busted)
                                         value = -1; // Negative score if busted.
                                      }
};


#endif // BLACKJACKHAND_H_INCLUDED
