// This program will convert numbers into roman numbers
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string roman_letter;
    int number, number2;
    const int roman = 7;
    string roman_letters[roman] = {"L", "XL", "X", "IX", "V", "IV", "I"};
    int numbers[roman] = {50, 40, 10, 9, 5, 4, 1};

    cout << "I can convert any number from 1 to 50 into a roman numeral. If you want to end the program enter 0. Please enter a number in decimal form: ";
    cin  >> number;
    number2 = number;

    if (number == 0)
    {
        cout << "Goodbye\n";
    }

    while (number > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (numbers[i] <= number)
            {
                roman_letter += roman_letters[i];
                number -= numbers[i];
                i=7;
            }
        }
    }
    cout << "Your number " << number2 << " now is " << roman_letter << endl;
    return 0;
}