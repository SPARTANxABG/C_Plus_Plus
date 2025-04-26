// This program creates random additions for young students
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Label corresponding variables
    unsigned seed;
    double addition, addition_2, answer, correct_answer;

    // Label seed
    seed = time(0);

    // Label srand and additions
    srand(seed);
    addition = rand() % (50 - 10 + 1) + 10;
    addition_2 = rand() % (50 - 10 + 1) + 10;

    // Create correct answer to show student
    correct_answer = addition + addition_2;

    // Create addition problem
    cout << "\n"
         << "What is the total amount when adding the two numbers?: \n"
         << "\n"
         << " " << addition << " \n"
         << "+" << addition_2 << " \n"
         << "---\n";
    cin  >> answer;

    // Create an If statement and display answer
    cout << "\n";
    if (answer == correct_answer)
    {
        cout << "You got the right answer! Great Job! :)\n";
    }
    else if (answer != correct_answer)
    {
        cout << "Your answer is incorrect. The correct answer was " << correct_answer << ".\n";
    }
    cout << "\n";
    return 0;
}