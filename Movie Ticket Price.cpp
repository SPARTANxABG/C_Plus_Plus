// This program calculates the grand total for movie tickets
#include <iostream>
#include <string>
using namespace std;

int main()
{
        double childticket, adultticket, childticketprice, adultticketprice, totalchildprice, totaladultprice, grandtotal;

        string movietitle;

        // set child ticket price
        childticketprice = 5;

        // set adult ticket price
        adultticketprice = 11;

        // obtain movie chosen by user
        cout << "Welcome to CineMovies! Which movie do you wish to watch today? ";
        cin  >> movietitle;

        // get number of child tickets
        cout << "How many child tickets do you wish to purchase? Each child ticket is $5.00: ";
        cin  >> childticket;

        // get number of adult tickets
        cout << "How many adult tickets do you wish to purchase? Each adult ticket is $11.00: ";
        cin  >> adultticket;

        // calculate the total child price
        totalchildprice = childticket * childticketprice;

        // display the total child price
        cout << "The total price for child ticket(s) is $" << totalchildprice;

        // calculate the total adult price
        totaladultprice = adultticket * adultticketprice;

        // display the total adult price
        cout << ". The total price for adult ticket(s) is $" << totaladultprice;

        // calculate grand total
        grandtotal = totalchildprice + totaladultprice;

        // display grand total
        cout << ". You chose the movie " << movietitle;
        cout << ". Your total amount is $" << grandtotal << endl;
        return 0;
}