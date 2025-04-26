// This program finds the perimeter of a rectangle
#include <iostream>
using namespace std;

int main()
{
    // Init the variables
    int rectangle_side_x;
    int rectangle_side_y;
    int total_side;
    int perimeter;

    // Assign each side their lenghts
    rectangle_side_x = 3;
    rectangle_side_y = 2;

    // Assign total side
    total_side = rectangle_side_x + rectangle_side_y;

    // Calculate perimeter
    perimeter = 2 * total_side;

    // Show the value
    cout << "The perimeter of a rectangle with sides " << rectangle_side_x << " and " << rectangle_side_y << " is " << perimeter << endl;
    return 0;
}