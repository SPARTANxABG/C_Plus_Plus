// This program calculates the expenses for a flower garden display.
#include <iostream>
using namespace std;

int main()
{
        double soil, flowerseeds, fence, total;

        // get cost of the soil
        cout << "How much does soil cost? ";
        cin  >> soil;

        //get cost of flower seeds
        cout << "How much does flower seeds cost? ";
        cin  >> flowerseeds;

        //get cost of the fence
        cout << "How much does a fence cost? ";
        cin  >> fence;

        // calculate the total
        total = soil + flowerseeds + fence;

        // display total
        cout << "The total $$ is =" << total << endl;
        return 0;
}