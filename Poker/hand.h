#pragma once
#ifndef _HAND_H_
#define _HAND_H_

#include "card.h"
#include <vector>

class Hand
{
public:
    void add(Card card);

    void showHand();

    void check();

private:
    std::vector< Card > cards;
};
#endif