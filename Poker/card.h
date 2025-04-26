#pragma once
#ifndef _CARD_H_
#define _CARD_H_

#include <string>

class Card
{
public:
    typedef enum SUITS { CLUBS = 1, DIAMONDS, HEARTS, SPADES } SUITES;

    typedef enum COUNT { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } COUNT;

    Card();

    Card(Card::SUITS _suit, Card::COUNT _val);

    std::string str();

    SUITS getSuit();

    COUNT getValue();

private:
    Card::SUITS suit;

    Card::COUNT value;

    std::string valToStr();

    std::string suitToStr();
};
#endif