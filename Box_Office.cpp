// This program finds the revenue for a movie theater and distributor for a movie
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    // Label the constant and variables
    const double theater = 0.8;
    const double distributor = 0.2;

    double gross_box, distributor_revenue, net_box, adult_ticket, child_ticket, child_price, adult_price;

    string movie_title;

    // Set child ticket price and adult ticket price
    child_price = 6;
    adult_price = 10;

    // Ask for movie title
    cout << "\n"
         << "This program will find a theater's gross and net box office revenue for a movie. Please enter the movie title here: ";
    getline(cin, movie_title);

    // Ask for number of child and adult tickets sold
    cout << "\n"
         << "Please enter the amount of child tickets sold for the movie: ";
    cin  >> child_ticket;
    cout << "\n"
         << "Please enter the amount of adult tickets sold for the movie: ";
    cin  >> adult_ticket;

    // Calculate gross box
    gross_box = (adult_price * adult_ticket) + (child_price * child_ticket);

    // Calculate amount paid to distributor
    distributor_revenue = gross_box * distributor;

    // Calculate net box
    net_box = gross_box * theater;

    // Show answers to user
    cout << "\n"
         << "Movie Name: " << movie_title << "\n"
         << "Adult Tickets Sold: " << adult_ticket << "\n"
         << "Child Tickets Sold: " << child_ticket << "\n"
         << "Gross Box Office Revenue: $" << gross_box << "\n"
         << "Amount Paid to Distributor: -$" << distributor_revenue << "\n"
         << "Net Box Office Revenue: $" << net_box << "\n"
         << "\n";
    return 0;
}