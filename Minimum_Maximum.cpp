// This program will figure out which number is higher
#include <iostream>
using namespace std;

int main()
{
    // Label corresponding variables
    double responce_1, repsonce_2;

    // Ask user for two random numbers
    cout << "\n"
         << "Hello! I can tell you which number is bigger than the other one. Please type in a random number: ";
    cin  >> responce_1;
    cout << "\n"
         << "Please type in another random number other than " << responce_1 << ": ";
    cin  >> repsonce_2;

    // Create an If statement and show answer
    cout << "\n";
    if (responce_1 > repsonce_2)
    {
        cout << "Number " << responce_1 << " is bigger than number " << repsonce_2 << ".\n";
    }
    else if (responce_1 < repsonce_2)
    {
        cout << "Number " << repsonce_2 << " is bigger than number " << responce_1 << ".\n";
    }
    cout << "\n";
    return 0;
}