#ifndef DECKCARDS_H_INCLUDED
#define DECKCARDS_H_INCLUDED
#include <vector>
#include "Card.h"
class DeckCards
{
private:
    std::vector<Card> deck;
    int cardsNum;

    // Rearrange the cards.
public:
    void shuffleCards();

    // Retrieving the card by index
    Card index(unsigned);
    DeckCards();

};

#endif // DECKCARDS_H_INCLUDED
