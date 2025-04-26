#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n, balance;

    balance = 1000;

    cout << "Welcome to Small Casinos Simulator. This program has two games: Poker and Blackjack.\n\n";
    cout << "You start with $1000 and BlackJack cost $100 to play. Poker is free to play.\n";
    jmp:
    cout << "\nPlease choose between the following options: \n\n";
    cout << " 1) Poker\n 2) BlackJack\n 3) Check Balance\n 4) Exit Casino\n";
    cin >> n;

    if ( n == 1)
    {
        cout << "\nWelcome to Poker!\n\nThis game can be played with up to four players and it is free to play.\n\n" << endl;

        vector< Hand > hands;
        Deck deck;
        int players;
        int sizeOfHand = 5;

        srand(time(NULL));

        cout << "Please enter the number of players: ";
        cin >> players;

        deck.Shuffle();

        for (int i = 0; i < players; i++)
        {
            hands.push_back(Hand());
        }

        for (int i = 0; i < sizeOfHand; i++)
        {
            vector<Card> dealCards = deck.Deal(players);

            for (int j = 0; j < hands.size(); j++)
            {
                Hand hand = hands[j];
                hand.add(dealCards[j]);
                hands[j] = hand;
            }
        }

        for (int i = 0; i < hands.size(); i++)
        {
            Hand hand = hands[i];
            cout << "Player " << i + 1 << " hand:  ";
            hand.showHand();
        }

        goto jmp;
    }

    else if (n == 2)
    {
        char choice = 'y';
        int card1, card2, hitCard, sum = 0, dealerSum = 18;

        while (choice == 'y')
        { 
            balance = balance - 100;

            cout << "\nWelcome to BlackJack!\n\nThis is a single player game.\n\nYour Current Balance is: $" << balance << "\n\n";

            srand(time(0));

            cout << "This is your first two cards: ";
            card1 = (rand() % 10 + 1);
            card2 = (rand() % 10 + 1);
            cout << card1 << " AND " << card2 << "\n\n";

            sum = card1 + card2;

            cout << "Total sum of both cards is = " << sum << "\n\n";
            cout << "Do you want to hit? Or stand? (y = hit / n = stand): ";
            cin >> choice;
            cout << "\n\n";

            while (choice == 'y')
            {
                srand(time(0));
                hitCard = (rand() % 10) + 1;
                cout << "Here is your next card: " << hitCard << "\n\n";
                sum = sum + hitCard;
                cout << "New total is: " << sum << "\n\n";
                if (sum >= 21) 
                {
                    break;
                }
                cout << "Do you want to hit again? Or stand this time? (y = hit / n = stand): " << "\n\n";
                cin >> choice;
            }

            if (sum == dealerSum) 
            {
                cout << "PUSH! (tie) We have refunded you $100 back." << "\n\n";
                balance = balance + 100;
            }

            else if (sum > dealerSum && sum < 22) 
            {
                cout << "You beat the dealer! His hand was " << dealerSum << ". Your had was " << sum << ". You won $300!" << "\n\n";
                balance = balance + 300;
            }

            else if (sum >= 22) 
            {
                cout << "BUST! You lose!" << "\n\n";
            }

            else 
            {
                cout << "The dealer's hand was " << dealerSum << ". Your hand was " << sum << ". You lose!" << "\n\n";
            }

            cout << "Would you like to go again? (y/n)";
            cin >> choice;
            cout << endl;
        }
        goto jmp;
    }

    else if (n == 3)
    {
        cout << "\nHere is your current balance: $" << balance << "\nWe hope you're enjoying your time here.\n";
        goto jmp;
    }

    else if (n == 4)
    {
        cout << "Thank you for playing with us! Goodbye!\n\n";
        return 0;
    }
}