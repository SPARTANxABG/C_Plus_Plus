// This program calculates the total monthly housing cost and total annual cost
#include <iostream>
using namespace std;

int main()
{
    // Label the expenses
    float mortgage_payment, phone, utilites, cable;
    double monthly, annual, monthly_expense, annual_expense;

    // Label annual and monthly
    monthly = 31;
    annual = 12;

    // Ask user the cost for each expense
    cout << "\n"
         << "This program will calculate both monthly and annual costs for the following housing-related expenses:\n"
         << "\n"
         << "1) Rent or Mortgage payment\n"
         << "2) Phones\n"
         << "3) Utilites\n"
         << "4) Cable\n"
         << "\n"
         << "Please enter the monthly cost for each in order (1-4) as previously stated:\n";
    cin  >> mortgage_payment >> phone >> utilites >> cable;

    // Show each expense to make sure
    cout << "\n"
         << "Rent or Mortgage payment is: $" << mortgage_payment << ".\n"
         << "Phones is: $" << phone << ".\n"
         << "Utilities is: $" << utilites << ".\n"
         << "Cable is: $" << cable << ".\n";

    // Calculate montly expenses
    monthly_expense = (mortgage_payment + phone + utilites + cable) * monthly;

    // Calculate annual expenses
    annual_expense = monthly_expense * annual;

    // Show monthly and annual results
    cout << "\n"
         << "The monthly cost of these expenses are: $" << monthly_expense << ".\n"
         << "\n"
         << "The annual cost of these expenses are: $" << annual_expense << ".\n"
         << "\n";
    return 0;
}