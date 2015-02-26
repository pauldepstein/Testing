#include "Blackjack.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

void Blackjack::shuffle()
{
    Deck.shuffleCards();
}

void Blackjack::initialDeal()
{
    shuffle();
    vector<Card> dealer;
    vector<Card> player;

    // Deal in alternate fashion two cards each just as in a game
    player.push_back(Deck.index(0));
    dealer.push_back(Deck.index(1));
    player.push_back(Deck.index(2));
    dealer.push_back(Deck.index(3));

    DealerCards = BlackjackHand(dealer);
    PlayerCards = BlackjackHand(player);

}

void Blackjack::setResult()
{ // Score as highly as possible but bust (-1) if over 21.
    if(DealerCards.getValue() > PlayerCards.getValue())
        result = DEALER_WINS;

    else if(PlayerCards.getValue() > DealerCards.getValue())
        result = PLAYER_WINS;

    else
        result = PUSH;

}

void Blackjack::displayResult()const
{
    switch (result)
    {
    case DEALER_WINS:
    cout << "\n The dealer has won\n";
    break;

    case PLAYER_WINS:
    cout << "\n The player has won\n";
    break;

    case PUSH:
    cout << "\nThe game is a tie\n";
    break;

    default:
    throw domain_error("Unrecognised value for game. ");

    }
}
