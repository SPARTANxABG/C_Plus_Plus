// This program makes the user guess a random generated number
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Label corresponding variables
    unsigned seed;
    double guess, answer;

    // Label the seed
    seed = time(0);

    // Label srand and guess value
    srand(seed);
    answer = rand() % 9 + 1;

    // Create random number
    cout << "\n"
         << "Hello :) I thought of a number from 1 to 9 and I want you to guess the number that I'm thinking about. Please tell me your guess: ";
    cin  >> guess;

    // Create If statement and show answer
    cout << "\n";
    if (guess == answer)
    {
        cout << "Wow you guessed correctly! It was " << answer << "!\n";
    }
    else if (guess > answer)
    {
        cout << "Your guess is bigger than my answer :( It was actually " << answer << ".\n";
    }
    else if (guess < answer)
    {
        cout << "Your guess is smaller than my answer :( It was actually " << answer << ".\n";
    }
    cout << "\n";
    return 0;
}