// This program contains a select options to find the area and perimeter of either a circle, rectangle, or triangle
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // Label corresponding elements
    float pi, rectangle_area, triangle_area, circle_area, menu;
    float rectangle_perimeter, triangle_perimeter, circle_perimeter;
    float circle_radius;
    float rectangle_length, rectangle_width;
    float triangle_length, triangle_height, triangle_a, triangle_b;
    char start;

    // Assign some elements their defined variables
    pi = 3.14159;

    // Start program

    cout << "\n"
         << "Start program by entering 'Y': ";
    cin  >> start;

    while (start == 'y' || start == 'Y')
    {
     // Create menu
     cout << "\n"
         << "Geometry Calculator\n"
         << "\n"
         << "     1. Calculate the Area and Perimeter of a Circle\n"
         << "     2. calculate the Area and Perimeter of a Rectangle\n"
         << "     3. Calculate the Area and Perimeter of a Triangle\n"
         << "     4. Quit\n"
         << "\n"
         << "Enter your choice (1-4): ";
     cin >> menu;

     // Create a while and nested if, then, if statement
     cout << "\n";
    
     while (menu == 1)
     {
        cout << "Please enter the radius of the circle: ";
        cin  >> circle_radius;
        circle_area = pi * pow(circle_radius, 2);
        circle_perimeter = 2 * pi * circle_radius;
        cout << "\n"
             << "The Area of a circle with radius " << circle_radius << " is: " << circle_area << ".\n"
             << "\n"
             << "The Perimeter of a circle with radius " << circle_radius << " is: " << circle_perimeter << ".\n"
             << "\n";
        break;
     }
     while (menu == 2)
     {
        cout << "Please enter the length of the rectangle: ";
        cin  >> rectangle_length;
        cout << "Please enter the width of the rectangle: ";
        cin  >> rectangle_width;
        rectangle_area = rectangle_length * rectangle_width;
        rectangle_perimeter = 2 * (rectangle_length + rectangle_width);
        cout << "\n"
             << "The Area of a rectangle with length " << rectangle_length << " and width " << rectangle_width << " is " << rectangle_area << ".\n"
             << "\n"
             << "The Perimeter of a rectangle with length " << rectangle_length << " and width " << rectangle_width << " is " << rectangle_perimeter << ".\n"
             << "\n";
        break;
     }
     while (menu == 3)
     {
        cout << "Please enter the base length of the triangle: ";
        cin  >> triangle_length;
        cout << "please enter the heigth of the triangle: ";
        cin  >> triangle_height;
        cout << "Please enter the length of side A of the triangle: ";
        cin  >> triangle_a;
        cout << "Please enter the length of side B of the triangle: ";
        cin  >> triangle_b;
        triangle_area = (triangle_length * triangle_height) / 2;
        triangle_perimeter = triangle_a + triangle_b + triangle_length;
        cout << "\n"
             << "The Area of a triangle with length " << triangle_length << " and height " << triangle_height << " is " << triangle_area << ".\n"
             << "\n"
             << "The Perimeter of a triangle with side A " << triangle_a << ", side B " << triangle_b << " and length " << triangle_length << " is " << triangle_perimeter << ".\n"
             << "\n";
        break;
     }
     if (menu == 4)
     {
        cout << "\n";
        break;
     }
     while (menu != 1)
     {
        cout << "Please choose between 1-4!"
             << "\n";
        break;
     }
    } 
    return 0;
}