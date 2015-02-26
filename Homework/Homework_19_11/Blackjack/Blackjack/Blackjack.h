#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED
#include "Card.h"
#include "DeckCards.h"
#include "BlackjackHand.h"
#include <vector>
#include <iostream>
class Blackjack
{
    private:

        DeckCards Deck;
        // Cards held by dealer
        BlackjackHand DealerCards;

        // Cards held by player.
        BlackjackHand PlayerCards;

        // Cards in deck that have not been dealt to player or dealer.
        std::vector<Card> CardsInDeck;

        // Start out with two cards in initial deal.
        static const int NUM_INITIAL_CARDS = 2;

        enum Result{DEALER_WINS, PLAYER_WINS, PUSH};
        void shuffle();

    public:

        Blackjack(){}
          // Simulating the initial deal.
       void  initialDeal();

       // Determine who won
       void setResult();

       // Denote result
       Result result;

       void displayResult()const;
       void displayDealerHand()const
       {
           std::cout << "\nDealer's hand is as follows:\n";
           DealerCards.displayHand();
       }

       void displayPlayerHand()const
       {
           std::cout << "\nPlayer's hand is as follows:\n";
           PlayerCards.displayHand();
       }

};


#endif // BLACKJACK_H_INCLUDED
