#include "hand.h"
#include <iostream>
#include <iomanip>

void Hand::add(Card card)
{
    Hand::cards.push_back(card);
}

void Hand::showHand()
{
    for (unsigned i = 0; i < Hand::cards.size(); i++)
    {
        std::cout << std::setw(3) << Hand::cards[i].str() << " ";
    }
    check();
    std::cout << std::endl;
}

void Hand::check()
{
    std::vector<int> suits(5, 0);
    std::vector<int> count(15, 0);
    std::string handType;

    for (int i = 0; i < cards.size(); i++)
    {
        suits[cards[i].getSuit()]++;
        count[cards[i].getValue()]++;
    }

    bool flushSeen = false;
    bool fourOfaKindSeen = false;
    bool threeOfaKindSeen = false;
    bool twoPairSeen = false;
    bool onePairSeen = false;

    for (int i = 0; i < 15; i++)
    {
        if (count[i] == 4)
        {
            fourOfaKindSeen = true;
        }

        else if (count[i] == 3)
        {
            threeOfaKindSeen = true;
        }

        else if (count[i] == 2)
        {
            if (onePairSeen)
            {
                twoPairSeen = true;
            }

            else
            {
                onePairSeen = true;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (suits[i] == cards.size())
        {
            flushSeen = true;
        }

    }

    if (fourOfaKindSeen)
    {
        std::cout << "  Four of A Kind";
    }

    else if (flushSeen)
    {
        std::cout << "  Flush";
    }

    else if (threeOfaKindSeen)
    {
        std::cout << "  Three of A Kind";
    }

    else if (twoPairSeen)
    {
        std::cout << "  Two Pair";
    }

    else if (onePairSeen)
    {
        std::cout << "  One Pair";
    }

    else
    {
        std::cout << "";
    }
}