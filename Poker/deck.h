#pragma once
#ifndef _DECK_H_
#define _DECK_H_

#include "card.h"
#include <vector>

class Deck
{
public:
    Deck();

    void Shuffle();

    void ShowDeck();

    std::vector<Card> Deal(int count);

private:
    std::vector<Card> cards;
};
#endif