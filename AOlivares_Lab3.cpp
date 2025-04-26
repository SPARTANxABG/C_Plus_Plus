// AOlivares_Lab3.cpp

#include <iostream>

using namespace std;

int hailstone(int n)
{
	cout << n << endl;

	if (n == 1)
	{
		return 1;
	}

	else
	{
		if (n % 2 == 0)
		{
			return 1 + hailstone(n / 2);
		}

		else
		{
			return 1 + hailstone(3 * n + 1);
		}
	}
}

int main()
{
	int n, count;

	cout << "Enter a number for the Collatz Conjecture: ";
	cin >> n;

	cout << "The Collatz Conjecture for " << n << " is: " << endl;

	count = hailstone(n);

	cout << "The number of steps was: " << count << endl;

	return 0;
}