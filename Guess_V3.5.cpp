// This program is a guessing game from 1-100 with the number of guesses displayed to the user
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

void guess_high(double guess, double answer);
void guess_low(double guess, double answer);
void guess_equal(double guess, double answer);

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
         << "Hello there! Would you like to play a guessing game? (Y/N)";
    cin  >> start;

    //Create a while statement
    cout << "\n";
    while (start == 'Y' || start == 'y')
    {
        cout << "I have a number from 1 to 100. Can you guess my number?: ";
        cin  >> guess;
        while (guess > answer)
        {
            guess_high(guess, answer);
            break;    
        }
        while (guess < answer)
        {
            guess_low(guess, answer);
            break;
        }
        if (guess == answer)
        {
            guess_equal(guess, answer);
            break;
        }
    }
    if (start == 'N' || start == 'n')
    {
        cout << "Maybe next time we'll play. Bye!"
             << "\n";
    }
    return 0;
}

// Create void statements

void guess_high(double guess, double answer)
{
    while (guess > answer)
    {
        cout << "\n"
             << "Your guess is too high. Try guessing again!\n";
        break;
    }
}

void guess_low(double guess, double answer)
{
    while (guess < answer)
    {
        cout << "\n"
             << "Your guess is too low. Try guessing again!\n";
        break;
    }
}

void guess_equal(double guess, double answer)
{
    if (guess == answer)
    {
        cout << "\n"
             << "Your guess was correct! It was " << answer << "!\n";
    }
}