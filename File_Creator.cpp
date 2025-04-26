// This program will create .txt files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ofstream outputFile;
    string response, filename, start, line;
    char next;

    // Open the output file
    outputFile.open("Message.txt");

    cout << "\n"
         << "Hello this program will create a .txt file named 'Message.txt'"
         << "\n";

    // Create for statement
    for (int count = 1; count <= 10; count++)
    {
        cout << "\n"
             << "What would you like to add in your .txt" << count << "?: ";
        getline(cin.ignore(),response);
        outputFile << response << endl;

        cout << "\n"
             << "Would you like to add more? 'Y' or 'N'? ";
        cin  >> next;

    // Create while statement
        while (next == 'Y'|| next == 'y')
        {
            cout << "\n"
                 << "What else would you like to add in your .txt" << count << "?: ";
            getline(cin.ignore(),response);
            outputFile << response << endl;
            break;
        }
        if (next == 'N' || next == 'n')
        {
            cout << "\n"
                 << "Done!";
            break;
        }
    }
    outputFile.close();

    cout << "\n"
         << "I hope this worked"
         << "\n";
    return 0;
}