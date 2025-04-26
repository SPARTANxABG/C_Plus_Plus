// This program finds the area of a rectangle
#include <iostream>
using namespace std;

int main()
{
    // Init the variables
    float rectangle_side_x;
    float rectangle_side_y;
    float area;

    // Assign each side their lenght
    rectangle_side_x = 5.13;
    rectangle_side_y = 2.2;

    // Calculate area
    area = rectangle_side_x * rectangle_side_y;

    // Show total area
    cout << "The Area of a rectangle with sides " << rectangle_side_x << " and " << rectangle_side_y << " is " << area << endl;
    return 0;
}