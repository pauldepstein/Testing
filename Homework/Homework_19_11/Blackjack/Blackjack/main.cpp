#include <iostream>
#include <string>
#include "stringHandling.h"
#include "Card.h"
#include "DeckCards.h"
#include "Blackjack.h"
#include <vector>

using namespace std;

// Playing 5 games of blackjack.
int main()
{
    /*cout << "Hello world!" << endl;
    string str = " 2 3   3 ";
    str = removeSpaces(str);
    cout<<"\n" + str;

    for(int i = 0; i < 52; i++)
    {
        Card c = Card::cardFromCode(i);
        cout << endl;
        cout << c.getDenomination() << endl;
        cout << c.getString() << endl;
        cout << c.getValue() << endl;
        cout << c.getSuit() << endl;

    } */

   /* DeckCards cards1;
    DeckCards cards2;
    DeckCards cards3;

    cards1.shuffleCards();
    cards2.shuffleCards();
    cards3.shuffleCards();

    for(int i = 0; i < 10; i++)
    {
        cout << cards1.index(i).getString() << endl;
        cout << cards2.index(i).getString() << endl;
        cout << cards3.index(i).getString() << endl;
        cout << endl << endl << endl;
    } */
    const int GAMES = 20;

    for(int i = 0; i<GAMES; i++)
    {
       Blackjack blackjack = Blackjack();
       blackjack.initialDeal();
       blackjack.setResult();
       blackjack.displayDealerHand();
       blackjack.displayPlayerHand();
       blackjack.displayResult();
    }

    return 0;
}
