#include <iostream>
#include <iomanip>
using namespace std;

int answer, number, number2;

int main()
{
    cout << "Enter number: ";
    cin  >> number;

    cout << "Divide by what number: ";
    cin  >> number2;

    answer = number / number2;
    cout << "Answer is: " << answer << "\n";

    return 0;
}