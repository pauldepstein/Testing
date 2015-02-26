# include "Card.h"
# include "stringHandling.h"
# include <string>
# include <stdexcept>
# include <cctype>

using std::string;

Card::Card(Denomination number, Suit suitVal): denomination(number), suit(suitVal)
{
    // string representation which is of the form 2D for two of diamonds.
    string firstChar;
    string secondChar;

    switch (suit)
    {
      case CLUBS:
        secondChar = "C";
        break;

      case DIAMONDS:
        secondChar = "D";
        break;

      case HEARTS:
        secondChar = "H";
        break;

      case SPADES:
        secondChar = "S";
        break;

      default:
        throw std::domain_error("Undefined Suit");

    }

    // Check that denomination is in required range.
    if(denomination > 12)
        throw std::domain_error("Undefined Denomination");

    // Characters for denom are A for ace, 2,3,..,9, T for ten
    // J for Jack, Q for Queen, K for King.

    switch(denomination)
    {
      case ACE:
        firstChar = "A";
        value = 11;
        break;

      case TEN:
         firstChar = "T";
         value = 10;
         break;

      case JACK:
         firstChar = "J";
         value = 10;
         break;

      case QUEEN:
         firstChar = "Q";
         value = 10;
         break;

      case KING:
         firstChar = "K";
         value = 10;
         break;

      default: // 2,3,4...,9
         value = denomination + 1;
         firstChar = intToString(value);

    }

    stringRep = firstChar + secondChar;
}

// Obtaining a card from its string representation.
Card Card::cardFromCode(string& code)
{
    const string trimmedCode = removeSpaces(code);
    if(trimmedCode.size() != 2)
        throw std::domain_error("Codes should have two characters");

    Denomination denom;
    Suit suitVal;

    switch(toupper(trimmedCode[0]))
    {
      case 'A':
        denom = ACE;
        break;

      case '2':
        denom = TWO;
        break;

      case '3':
        denom = THREE;
        break;

      case '4':
        denom = FOUR;
        break;

      case '5':
        denom = FIVE;
        break;

      case '6':
        denom = SIX;
        break;

      case '7':
        denom = SEVEN;
        break;

      case '8':
        denom = EIGHT;
        break;

      case '9':
        denom = NINE;
        break;

      case 'T':
        denom = TEN;
        break;

      case 'J':
        denom = JACK;
        break;

      case 'Q':
        denom = QUEEN;
        break;

      case 'K':
        denom = KING;
        break;

      default:
        throw std::domain_error("Undefined code");

    }

    switch(toupper(trimmedCode[1]))
    {
       case 'C' :
         suitVal = CLUBS;
         break;

       case 'D' :
         suitVal = DIAMONDS;
         break;

       case 'H' :
        suitVal = HEARTS;
        break;

       case 'S' :
        suitVal = SPADES;
        break;

       default :
         throw std::domain_error("Undefined Code");

    }

    return Card(denom, suitVal);
}

// Translating the integers from 0 to 51 into unique cards.
Card Card::cardFromCode(int n)
{
    const int SuitsNum = 4; // four suits.
    const int DenomsNum = 13; // 13 card values.
    if(n < minCard || n > maxCard )
        throw std::domain_error("Out of range -- no card can be assigned");

    return Card(Denomination(n%DenomsNum), Suit(n%SuitsNum));
}

