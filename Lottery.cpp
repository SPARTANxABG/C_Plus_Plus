// This program will simulate a lottery
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    unsigned seed;
    seed = time(0);
    srand(seed);
    int lottery_number, player_number, player_number_2, player_number_3, player_number_4, player_number_5;
    const int winning_digits = 5;
    const int player_numbers = 5;
    int lottery_numbers[winning_digits] = {rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9};
    bool arraysEqual = true;
    int i = 0;

    cout << "This is a lottery simulator. Please enter 5 digits between 0 and 9 to participate: "
         << "\n";
    cin  >> player_number
         >> player_number_2
         >> player_number_3
         >> player_number_4
         >> player_number_5;
    cout << "\n";

    int player[player_numbers] = {player_number, player_number_2, player_number_3, player_number_4, player_number_5};

    while (arraysEqual &&  i < 5)
    {
        if (lottery_numbers[i] != player[i])
           arraysEqual = false;
        i++;
        for (int i = 0; i < 5; i++)
        {
            cout << "\n"
                 << "Your chosen numbers are: " << player[i] << " and the winning numbers are: " << lottery_numbers[i] << "\n";
        }
        break;
    }
    if (arraysEqual)
        cout << "The arrays are equal\n";
    return 0;
}