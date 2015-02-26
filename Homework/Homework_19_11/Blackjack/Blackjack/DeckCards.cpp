#include "DeckCards.h"
#include "Card.h"
#include <algorithm>
#include <vector>
#include <stdexcept>

DeckCards::DeckCards():cardsNum(52)
{
   for(int i = 0; i<cardsNum; i++)
       deck.push_back(Card::cardFromCode(i));
}

// Shuffle cards using random shuffle.
void DeckCards::shuffleCards()
{
   std::random_shuffle(deck.begin(), deck.end());
}

// Indexing
Card DeckCards::index(unsigned idx)
{
    if(idx >= deck.size() )
        throw std::domain_error("Index out of range");

     return deck[idx];
}
