// AOlivares_Lab4.cpp

#include <iostream>

using namespace std;

void recursiveSelect(int arr[], int i, int SIZE)
{
	int min = i;

	for (int j = i + 1; j < SIZE; j++)
	{
		if (arr[j] < arr[min])
		{
			min = j;
		}
	}

	int temp = arr[min];
	arr[min] = arr[i];
	arr[i] = temp;

	if (i + 1 < SIZE)
	{
		recursiveSelect(arr, i + 1, SIZE);
	}
}

void recursiveInsert(int arr[], int SIZE)
{
	if (SIZE <= 1)
	{
		return;
	}

	recursiveInsert(arr, SIZE - 1);

	int last = arr[SIZE - 1];
	int j = SIZE - 2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}

	arr[j + 1] = last;
}

void printArr(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main()
{
	int array[20];

	for (int i = 0; i < 20; i++)
	{
		array[i] = rand() % 200;
	}

	cout << "\nThe following numbers in the array before sorting: " << endl;
	printArr(array, 20);

	recursiveInsert(array, 20);

	cout << "\nThe following numbers in the array after sorting: " << endl;
	printArr(array, 20);

	return 0;
}