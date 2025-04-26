#include "card.h"
#include <sstream>

using namespace std;

Card::Card()
{
}

Card::Card(Card::SUITS _suit, Card::COUNT _val)
{
    suit = _suit;
    value = _val;
}

std::string Card::str()
{
    ostringstream os;
    os << valToStr() << suitToStr();
    return os.str();
}

std::string Card::valToStr()
{
    COUNT c = getValue();
    if (c >= 2 && c <= 10)
    {
        ostringstream os;
        os << c;
        return os.str();
    }

    else if (c == 11)
    {
        return "J";
    }

    else if (c == 12)
    {
        return "Q";
    }

    else if (c == 13)
    {
        return "K";
    }

    else if (c == 14)
    {
        return "A";
    }

}

std::string Card::suitToStr()
{
    SUITS s = getSuit();
    if (s == 1)
    {
        return "C";
    }

    else if (s == 2)
    {
        return "D";
    }

    else if (s == 3)
    {
        return "H";
    }

    else if (s == 4)
    {
        return "S";
    }

    else
    {
        return "";
    }
}

Card::SUITS Card::getSuit()
{
    return suit;
}

Card::COUNT Card::getValue()
{
    return value;
}