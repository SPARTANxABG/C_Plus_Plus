// This program finds total calories consumed from cookies
#include <iostream>
using namespace std;

int main()
{
    // Label corresponding items
    int cookies_ate;
    double cookie_calorie, calories, total_calories;

    // Label each appropriate item
    calories = 240;
    cookie_calorie = 24;

    // Ask user how many cookies were eaten
    cout << "\n"
         << "This program will find how many calories were consumed for each cookie eaten.\n"
         << "The recommended serving is 10 cookies, having " << calories << " calories.\n"
         << "How many cookies were eaten? ";
    cin  >> cookies_ate;

    // Find out how many calories were consumed
    total_calories = cookie_calorie * cookies_ate;

    // Show answer to user
    cout << "\n"
         << "The amount of cookies that you ate were " << cookies_ate << " cookies.\n"
         << "\n"
         << "The total amount of calories consumed were " << total_calories << " calories."
         << "\n";
    return 0;
}