//This program is a tic-tac-toe game
#include <iostream>
#include <string>
using namespace std;

const int letter = 10;
string squares[letter] = {"0", "11", "12", "13", "21", "22", "23", "31", "32", "33"};
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

        cout << "Player " << player << ", type in a coordinate (ex: 11): ";
        cin  >> coordinate;

        letters = (player == 1) ? 'X' : 'O';

        if ( (coordinate == "11" && squares[1] == "11") )
        {
            squares[1] = letters;
            system("clear");
        }
        else if ( (coordinate == "12" && squares[2] == "12") )
        {
            squares[2] = letters;
            system("clear");
        }
        else if ( (coordinate == "13" && squares[3] == "13") )
        {
            squares[3] = letters;
            system("clear");
        }
        else if ( (coordinate == "21" && squares[4] == "21") )
        {
            squares[4] = letters;
            system("clear");
        }
        else if ( (coordinate == "22" && squares[5] == "22") )
        {
            squares[5] = letters;
            system("clear");
        }
        else if ( (coordinate == "23" && squares[6] == "23") )
        {
            squares[6] = letters;
            system("clear");
        }
        else if ( (coordinate == "31" && squares[7] == "31") )
        {
            squares[7] = letters;
            system("clear");
        }
        else if ( (coordinate == "32" && squares[8] == "32") )
        {
            squares[8] = letters;
            system("clear");

        }
        else if ( (coordinate == "33" && squares[9] == "33") )
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

    cout << "      1     2     3   " << "\n"
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
    else if ( (squares[1] != "11") && (squares[2] != "12") && (squares[3] != "13") && (squares[4] != "21") && (squares[5] != "22") && (squares[6] != "23") && (squares[7] != "31") && (squares[8] != "32") && (squares[9] != "33") )
    {
        return 0;
    }
    else
    {
        return -1;
    }
}