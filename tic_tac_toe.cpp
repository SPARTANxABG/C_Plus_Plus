//This program is a tic-tac-toe game
#include <iostream>
#include <string>
using namespace std;

const int letter = 10;
string squares[letter] = {"0", "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3"};
void game_board();
int win_condition();

int main()
{
    int player = 1, i;
    string coordinate;
    char letters;

    do
    {
        game_board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", type in a coordinate (ex: A1): ";
        cin  >> coordinate;

        letters = (player == 1) ? 'X' : 'O';

        if ( (coordinate == "A1" && squares[1] == "A1") )
        {
            squares[1] = letters;
            system("clear");
        }
        else if ( (coordinate == "A2" && squares[2] == "A2") )
        {
            squares[2] = letters;
            system("clear");
        }
        else if ( (coordinate == "A3" && squares[3] == "A3") )
        {
            squares[3] = letters;
            system("clear");
        }
        else if ( (coordinate == "B1" && squares[4] == "B1") )
        {
            squares[4] = letters;
            system("clear");
        }
        else if ( (coordinate == "B2" && squares[5] == "B2") )
        {
            squares[5] = letters;
            system("clear");
        }
        else if ( (coordinate == "B3" && squares[6] == "B3") )
        {
            squares[6] = letters;
            system("clear");
        }
        else if ( (coordinate == "C1" && squares[7] == "C1") )
        {
            squares[7] = letters;
            system("clear");
        }
        else if ( (coordinate == "C2" && squares[8] == "C2") )
        {
            squares[8] = letters;
            system("clear");

        }
        else if ( (coordinate == "C3" && squares[9] == "C3") )
        {
            squares[9] = letters;
            system("clear");

        }
        else
        {
            cout << "You can't place on that coordinate. Press enter and type another coordinate";
            player--;
            cin.ignore();
            cin.get();
            system("clear");
        }
        i = win_condition();
        player++;
    }
    while(i == -1);

    system("clear");
    game_board();

    if (i == 1)
    {
        cout << "Player " << --player << " win! Press enter to exit.";
    }
    else
    {
        cout << "It's a draw! Press enter to exit.";
    }
    cin.ignore();
    cin.get();
    return 0;
}

void game_board()
{
    cout << "\n"
         << "Player 1 (X) - Player 2 (O)\n"
         << "\n";

    cout << "      A     B     C   " << "\n"
         << "   ___________________" << "\n"
         << "   |     |     |     |" << "\n"
         << "1  |  " << squares[1] << " |  " << squares[4] << " |  " << squares[7] << " |" << "\n"
         << "   |_____|_____|_____|" << "\n"
         << "   |     |     |     |" << "\n"
         << "2  |  " << squares[2] << " |  " << squares[5] << " |  " << squares[8] << " |" << "\n"
         << "   |_____|_____|_____|" << "\n"
         << "   |     |     |     |" << "\n"
         << "3  |  " << squares[3] << " |  " << squares[6] << " |  " << squares[9] << " |" << "\n"
         << "   |_____|_____|_____|" << "\n";
}

int win_condition()
{
    if ( (squares[1] == squares[2]) && (squares[2] == squares[3]) )
    {
        return 1;
    }
    else if ( (squares[4] == squares[5]) && (squares[5] == squares[6]) )
    {
        return 1;
    }
    else if ( (squares[7] == squares[8]) && (squares[8] == squares[9]) )
    {
        return 1;
    }
    else if ( (squares[1] == squares[4]) && (squares[4] == squares[7]) )
    {
        return 1;
    }
    else if ( (squares[2] == squares[5]) && (squares[5] == squares[8]) )
    {
        return 1;
    }
    else if ( (squares[3] == squares[6]) && (squares[6] == squares[9]) )
    {
        return 1;
    }
    else if ( (squares[1] == squares[5]) && (squares[5] == squares[9]) )
    {
        return 1;
    }
    else if ( (squares[3] == squares[5]) && (squares[5] == squares[7]) )
    {
        return 1;
    }
    else if ( (squares[1] != "A1") && (squares[2] != "A2") && (squares[3] != "A3") && (squares[4] != "B1") && (squares[5] != "B2") && (squares[6] != "B3") && (squares[7] != "C1") && (squares[8] != "C2") && (squares[9] != "C3") )
    {
        return 0;
    }
    else
    {
        return -1;
    }
}