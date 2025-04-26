// This program will find the are of two rectangles and determine which rectangle is greater
#include <iostream>
using namespace std;

int main()
{
    // Init the variables
    float rectangle_a_x, rectangle_a_y, rectangle_b_x, rectangle_b_y, area_a, area_b;

    // Ask user for each side for Rectangle A
    cout << "\n"
         << "I can determine which are of two rectangles is bigger than the other.\n"
         << "\n"
         << "Please type the lenght for Rectangle A: ";
    cin  >> rectangle_a_x;
    cout << "Please type the width for Rectangle A: ";
    cin  >> rectangle_a_y;
    cout << "\n";

    // Calculate area for Rectangle A
    area_a = rectangle_a_x * rectangle_a_y;

    // Display area for Rectangle A to user
    cout << "The area for Rectangle A is " << area_a << ".\n";

    // Ask user for each side for Rectangle B
    cout << "\n"
         << "Please type the lenght for Rectangle B: ";
    cin  >> rectangle_b_x;
    cout << "Please type the width for Rectangle B: ";
    cin  >> rectangle_b_y;
    cout << "\n";

    // Calculate area for Rectangle B
    area_b = rectangle_b_x * rectangle_b_y;

    // Display area for Rectangle B to user
    cout << "The area for Rectangle B is " << area_b << ".\n";

    // Create an If statement and display answer
    cout << "\n";
    if (area_a > area_b)
    {
        cout << "Rectangle A with area " << area_a << " is greater than Rectangle B with area " << area_b << ".\n";
    }
    else if (area_a < area_b)
    {
        cout << "Rectangle A with area " << area_a << " is less than Rectangle B with area " << area_b << ".\n";
    }
    else if (area_a == area_b)
    {
        cout << "Rectangle A with area " << area_a << " is equal to Rectangle B with area " << area_b << ".\n";
    }
    cout << "\n";
    return 0;
}