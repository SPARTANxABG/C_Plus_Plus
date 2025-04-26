// This program converts days into hours, minutes, and seconds
#include <iostream>
using namespace std;

int main()
{
    // Label the time variables
     int days;
     double hours, minutes, seconds, vacation_hours, vacation_minutes, vacation_seconds;

    // Label hours, minutes, and seconds
     hours = 24;
     minutes = 60;
     seconds = 60;

    // Ask user how many days they plan to stay
    cout << "\n"
         << "This program will convert days entered into hours, minutes, and seconds. \n"
         << "Please enter the number of days that you would like to spend in your next vacation: ";
    cin  >> days;

    // Convert
     vacation_hours = days * hours;
     vacation_minutes = vacation_hours * minutes;
     vacation_seconds = vacation_minutes * seconds;

    // Display the results
    cout << "\n"
         << "The number of days entered (" << days << " days) converted into hours would be " << vacation_hours << " hours.\n"
         << "\n"
         << "From days entered into minutes would be " << vacation_minutes << " minutes.\n"
         << "\n"
         << "For days into seconds would be " << vacation_seconds << " seconds.\n"
         << "\n";
         return 0;
}