#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
// Representing a playing card
#include <string>
class Card
{
public:
    enum Suit{CLUBS, DIAMONDS, HEARTS, SPADES};
    enum Denomination{ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    Card(Denomination, Suit); // string representation and value of card set in constructor.

    // get string representation
    std::string getString() const {return stringRep;}

    Suit getSuit() const {return suit;}

    Denomination getDenomination() const {return denomination;}

    // get value of card -- for example royal cards are generally equal to 10.
    int getValue() const {return value;}

    // Obtaining a card from its string representation.
    static Card cardFromCode (std::string&);

    // Obtaining a card from an integer between 0 and 51.
    static Card cardFromCode(int);


private:
    // string representation and value.
    std::string stringRep;
    int value;

    Suit suit;
    Denomination denomination;

    // Cards are from 0 to 51.
    static const int minCard = 0;
    static const int maxCard = 51;
};


#endif // CARD_H_INCLUDED
