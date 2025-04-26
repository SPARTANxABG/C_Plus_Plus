// This program is an improvement to the random addition generator
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void menu_1(float addition, float addition_2, float correct_answer_1, float answer_1);
void menu_2(float subtraction, float subtraction_2, float answer_2, float correct_answer_2);
void menu_3(float multiplication, float multiplication_2, float answer_3, float correct_answer_3);
void menu_4(float square, float answer_4, float correct_answer_4);
void menu_5(float power, float answer_5, float correct_answer_5);

int main()
{
    // Label corresponding variables
    unsigned seed;
    float addition, addition_2, subtraction, subtraction_2, multiplication, multiplication_2, square, power;
    float answer_1, answer_2, answer_3, answer_4, answer_5, menu;
    float correct_answer_1, correct_answer_2, correct_answer_3, correct_answer_4, correct_answer_5;
    char start;

    // Label seed
    seed = time(0);

    // Label srand and additions
    srand(seed);
    addition = rand() % (50 - 10 + 1) + 10;
    addition_2 = rand() % (50 - 10 + 1) + 10;
    subtraction = rand() % (50 - 10 + 1) + 10;
    subtraction_2 = rand() % (50 - 10 + 1) + 10;
    multiplication = rand() % (50 - 10 + 1) + 10;
    multiplication_2 = rand() % (50 - 10  + 1) + 10;
    square = rand() % (50 - 10 + 1) + 10;
    power = rand() % (50 - 10 + 1) + 10;

    // Create correct answer to show student
    correct_answer_1 = addition + addition_2;
    correct_answer_2 = subtraction - subtraction_2;
    correct_answer_3 = multiplication * multiplication_2;
    correct_answer_4 = sqrt(square);
    correct_answer_5 = pow(power, 2);

    // Start program
    cout << "\n"
         << "Start the Program by entering 'Y': ";
    cin  >> start;

    // Create while statement and menu
    while (start == 'Y' || start == 'y')
    {
        cout << "\n"
             << "Math Tutor 3.0\n"
             << "\n"
             << "     1) Additions.\n"
             << "     2) Subtractions.\n"
             << "     3) Multiplications.\n"
             << "     4) Square Roots.\n"
             << "     5) Exponents.\n"
             << "     6) Exit program.\n"
             << "\n"
             << "Please choose from 1-6: ";
        cin  >> menu;

        // Create a nested while and if statement
        cout << "\n";
        while (menu == 1)
        {
            menu_1(addition, addition_2, correct_answer_1, answer_1);
            break;
        }

        while (menu == 2)
        {
            menu_2(subtraction, subtraction_2, answer_2, correct_answer_2);
            break;
        }

        while (menu == 3)
        {
            menu_3(multiplication, multiplication_2, answer_3, correct_answer_3);
            break;
        }

        while (menu == 4)
        {
            menu_4(square, answer_4, correct_answer_4);
            break;
        }

        while (menu == 5)
        {
            menu_5(power, answer_5, correct_answer_5);
            break;
        }

        if (menu == 6)
        {
            cout << "Shutting down. Goodbye :)"
                << "\n";
            break;
        }
    }
    return 0;
}

// Create void statements

void menu_1(float addition, float addition_2, float correct_answer_1, float answer_1)
{
    cout << "Addition!\n"
                 << "\n"
                 << "What is the total amount when adding these two numbers?: \n"
                 << "\n"
                 << " " << addition << " \n"
                 << "+" << addition_2 << " \n"
                 << "---\n";
    cin  >> answer_1;

    while (answer_1 != correct_answer_1)
    {
        cout << "That's not correct. Try again: ";
        cin  >> answer_1;
    }
    while (answer_1 == correct_answer_1)
    {
       cout << "\n"
            << "Correct! Good Job :)\n"
            << "\n";
        break;
    }
}

void menu_2(float subtraction, float subtraction_2, float answer_2, float correct_answer_2)
{
     cout << "Subtraction!\n"
         << "\n"
         << "What is the total amount when subtracting these two numbers?: \n"
         << "\n"
         << " " << subtraction << " \n"
         << "-" << subtraction_2 << " \n"
         << "---\n";
     cin  >> answer_2;

    while (answer_2 != correct_answer_2)
    {
        cout << "That's not correct. Try again: ";
        cin  >> answer_2;
    }
    while (answer_2 == correct_answer_2)
    {
        cout << "\n"
             << "Correct! Good Job :)\n"
             << "\n";
        break;
    }
}

void menu_3(float multiplication, float multiplication_2, float answer_3, float correct_answer_3)
{
    cout << "Multiplication!\n"
         << "\n"
         << "What is the total amount when multiplying these two numbers?: \n"
         << "\n"
         << " " << multiplication << "\n"
         << "x" << multiplication_2 << "\n"
         << "---\n";
    cin >> answer_3;

    while (answer_3 != correct_answer_3)
    {
        cout << "That's not correct. Try again: ";
        cin  >> answer_3;
    }
    while (answer_3 == correct_answer_3)
    {
        cout << "\n"
             << "Correct! Good Job :)\n"
             << "\n";
        break;
    }
}

void menu_4(float square, float answer_4, float correct_answer_4)
{
    cout << "Square Root!\n"
         << "\n"
         << "What is the Square root of " << square << "?: ";
    cin >> answer_4;

    while (answer_4 != correct_answer_4)
    {
        cout << "That's not correct. Try again: ";
        cin  >> answer_4;
    }
    while (answer_4 == correct_answer_4)
    {
        cout << "\n"
             << "Correct! Good Job :)\n"
             << "\n";
        break;
    }
}

void menu_5(float power, float answer_5, float correct_answer_5)
{
    cout << "Exponent!\n"
         << "\n"
         << "What is " << power << " to the power of 2?: ";
    cin  >> answer_5;

    while (answer_5 != correct_answer_5)
    {
        cout << "That's not correct. Try again: ";
        cin  >> answer_5;
    }
    while (answer_5 == correct_answer_5)
    {
        cout << "\n"
             << "Correct! Good Job :)\n"
             << "\n";
        break;
    }
}