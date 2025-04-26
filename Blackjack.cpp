#include<iostream> // heeader file for input and output
#include<cstdlib> //for random number function
#include<ctime>//for pseudo random integer srand() function

using namespace std;

int main() { // main function
	char ch = 'y'; // for 1st loop ch==y
	int num1, num2, num3, sum = 0, delsum = 18; // num1 for 1st random number , num2 for 2nd random number and num3 for each successive random number, sum for total, delsum for dealer sum
	while (ch == 'y') { // when user enter y
		srand(time(0)); //pseudo random integer
		cout << "First Cards ";
		num1 = (rand() % 10 + 1);// first random number +1 for generating between 1 and 10
		num2 = (rand() % 10 + 1);// second random number
		cout << num1 << ", "; //print number1
		cout << num2 << endl;//print number 2
		sum = num1 + num2;// sum of two cards
		cout << "Total:=" << sum << endl;
		cout << "Do you want other card? (y/n) ";
		cin >> ch;//for reading yes or no
		cout << endl;
		while (ch == 'y') { // when ch==y
			srand(time(0));////pseudo random integer
			num3 = (rand() % 10) + 1;// random number
			cout << "card: " << num3 << endl;
			sum = sum + num3;//sum of total
			cout << "total: " << sum << endl;
			if (sum >= 21) { //if sum >21 you are out of game bust
				break;
			}
			cout << "Do you want other card? (y/n) " << endl;
			cin >> ch;///for reading yes or no
		}
		if (sum == delsum) {//comparision between dedler sum equal to your sum
			cout << "PUSH" << endl;
		}
		else if (sum > delsum && sum < 22) { //if you sum is greater than dealer sum and less than 22 you win
			cout << "YOU WIN" << endl;
		}
		else if (sum >= 22) { // if your sum greater than 22 it is bust
			cout << "BUST" << endl;
		}
		else {// you will lose
			cout << "You lose" << endl;
		}
		cout << "Do you want to play another game? (y/n)";
		cin >> ch;// for reading yes or no
		cout << endl;
	}

}