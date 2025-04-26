// This program is a guessing game from 1-100 with the number of guesses displayed to the user
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <termcolor/termcolor.hpp>
using namespace std;
using namespace termcolor;

int main()
{
    // Label corresponding variables
    unsigned seed;
    double guess, answer;
    int count = 1;
    char start;

    // Label the seed
    seed = time(0);

    // Label srand and guess value
    srand(seed);
    answer = rand() % 100 + 1;

    // Start game
    cout << "\n"
         << "Hello there! Would you like to play a guessing game? (" << green << "Y" << white << "/" << red << "N" << white << ")";
    cin  >> start;

    //Create a while statement
    cout << "\n";
    while (start == 'Y' || start == 'y')
    {
        cout << "I have a number from 1 to 100. Can you guess my number?: ";
        cin  >> guess;
        while (guess > answer)
        {
            cout << "\n"
                 << red << "Your guess is too high. " << white << "Try guessing again!\n";
                 break;    
        }
        while (guess < answer)
        {
            cout << "\n"
                 << cyan << "Your guess is too low. " << white << "Try guessing again!\n";
                 break;
        }
        if (guess == answer)
        {
            cout << "\n"
                 << green << "Your guess was correct! " << white << "It was " << green << answer << white << "!\n";
                 break;
        }
    }
    if (start == 'N' || start == 'n')
    {
        cout << red << "Maybe next time we'll play. " << white << "Bye!"
             << "\n";
    }
    return 0;
}