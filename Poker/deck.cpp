#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck()
{
    Shuffle();
}

void Deck::Shuffle()
{
    cards.erase(cards.begin(), cards.end());

    for (int i = Card::CLUBS; i <= Card::SPADES; i++)
    {
        for (int j = Card::TWO; j <= Card::ACE; j++)
        {
            cards.push_back(Card(Card::SUITS(i), Card::COUNT(j)));
        }
    }

    random_shuffle(cards.begin(), cards.end());
}

void Deck::ShowDeck()
{
    for (int i = 0; i < cards.size(); i++)
    {
        Card c = cards[i];
        cout << c.str() << " ";
    }

    cout << std::endl << std::endl;
}

std::vector<Card> Deck::Deal(int count)
{
    vector<Card> dealCards;

    for (int i = 0; i < count; i++)
    {
        dealCards.push_back(Deck::cards[0]);
        Deck::cards.erase(Deck::cards.begin());
    }

    return dealCards;
}