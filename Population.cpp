// This program estimates the population of a city or planet
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

void info(float starting_population, float annual_birth_rate, float annual_death_rate, float number_years, float year);

int main()
{
    ofstream outputFile;
    string response, filename, start, line;
    float starting_population, annual_birth_rate, annual_death_rate, number_years;
    float year;

    starting_population = 0;
    annual_birth_rate = 0;
    annual_death_rate = 0;
    number_years = 0;

    info(starting_population, annual_birth_rate, annual_death_rate, number_years, year);

    year = -1; 

    return 0;
}

void info(float starting_population, float annual_birth_rate, float annual_death_rate, float number_years, float year)
{
    ofstream outputFile;
    string response, filename, start, line;

    //Create a new file to save the data
    outputFile.open("Population Estimator.txt");

    cout << "\n"
         << "Hello. This program is a population estimator.\n"
         << "This program will create a .txt file named 'Population Estimator' where you can access the data anytime."
         << "\n";

    // Create program
    cout << "\n"
         << "Please enter the starting size of a population: ";
    cin  >> starting_population;
    outputFile << "Starting population: " << starting_population << endl;

    cout << "\n"
         << "Please enter the annual birth rate as a decimal: ";
    cin  >> annual_birth_rate;
    outputFile << "Annual Birth rate: " << annual_birth_rate << endl;

    cout << "\n"
         << "Please enter the annual death rate as a decimal: ";
    cin  >> annual_death_rate;
    outputFile << "Annual Death rate: " << annual_death_rate << endl;

    cout << "\n"
         << "Please enter the number of years to estimate annual death and birth rate: ";
    cin  >> number_years;
    outputFile << "Number of years: " << number_years << endl;

    while(year < number_years)
    {
        starting_population = starting_population * (1 + annual_birth_rate) * (1 - annual_death_rate);
        year++;

        cout << "\n"
             << "In " << year << " years, the population will be " << starting_population << "."
             << "\n";
        outputFile << "Estimated population size in " << year << " years: " << starting_population << endl;
    }
    outputFile.close();
}