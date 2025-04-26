// AOlivares_Lab1.cpp

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ToDoItem
{
private:

	string itemText;
	bool status;

public:

	ToDoItem()
	{
		setStatus(false);
		setItemText("Unknown");
	}

	void setStatus(bool status)
	{
		this->status = status;
	}

	void setItemText(string itemText)
	{
		this->itemText = itemText;
	}

	string getItemText()
	{
		return itemText;
	}

	bool getStatus()
	{
		return status;
	}
};

void sizeIncrease(ToDoItem*& items, int size)
{
	ToDoItem* dbl = new ToDoItem[size * 2];
	for (int i = 0; i < size; i++)
	{
		dbl[i] = items[i];
	}

	delete[] items;
	items = dbl;
}

void menu()
{
	cout << "\nTo Do List\n";
	cout << "\n";
	cout << "1: Add an item\n";
	cout << "2: Toggle Item Status\n";
	cout << "3: List All Items\n";
	cout << "4: Exit List\n";
	cout << "\n";
	cout << ">>";
}

int main()
{
	char choice;
	int size = 5;

	ToDoItem* list = new ToDoItem[size];
	int index = 0;

	do
	{
		menu();
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
			case '1':
			{
				cout << "\nPlease add an item: ";
				string str;
				getline(cin, str);

				if (index == size)
				{
					sizeIncrease(list, size);
					list[index++].setItemText(str);
				}

				else
				{
					list[index++].setItemText(str);
				}
				break;
			}

			case '2':
			{
				int ch, i;
				do
				{
					cout << "Please toggle item status\n";
					cout << "\n";
					for (i = 0; i < index; i++)
					{
						cout << i + 1 << " ";

						if (list[i].getStatus() == false)
						{
							cout << "| Unfinished | ";
						}

						else
						{
							cout << "| Finished | ";
						}
						cout << list[i].getItemText() << "\n";
					}
					cout << i + 1 << " Return to main menu \n";
					cout << ">> ";

					cin >> ch;
					ch--;

					if (ch < i)
					{
						if (list[ch].getStatus() == false)
						{
							list[ch].setStatus(true);
						}

						else
						{
							cout << "Already finished\n";
						}
					}

					else if (ch == i)
					{
						break;
					}

					else
					{
						cout << "You have entered an incorrect choice\n";
					}
				}

				while (ch != i);
				break;
			}

			case '3':
			{
				cout << "\tList of items\n";
				cout << "\n";

				for (int i = 0; i < index; i++)
				{
					cout << list[i].getItemText() << " ";
					cout << setw(20);

					if (list[i].getStatus() == false)
					{
						cout << "Unfinished ";
					}

					else
					{
						cout << "Finished ";
					}

					cout << "\n";
					cout << "-----------------------------------------";
					cout << "\n";
				}
				break;
			}

			case '4':
			{
				cout << "\nExit successful!\n";

				break;
			}

			default:
			{
				cout << "You entered a choice please try again\n";
			}
		}
	}
	while (choice != '4');
}