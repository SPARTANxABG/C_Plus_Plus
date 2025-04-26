#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
	char cust_name[100];
	int order_no;
	float price;
	node* next;
}*front = NULL, *rear = NULL, *p = NULL, *np = NULL;

class order
{
public:
	void take_order();
	void close_order();
	void display_order();

};
void order::take_order()
{
	float order_price[10];
	int n, i;
	float price1 = 0.0;
	np = new node;
	cout << endl << "Enter customer name:";
	fflush(stdin);
	cin.get(np->cust_name, 100); 
	cout << "Enter the customer order number:";
	cin >> np->order_no;
	cout << "How many Items to be ordered(Check out from item list above):";
	cin >> n;
	cout << "Enter the prices from above list:" << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> order_price[i];
	}
	for (i = 1; i <= n; i++)
	{
		price1 = price1 + order_price[i];
	}
	np->price = price1;
	np->next = NULL;
	if (rear == NULL)
	{
		front = np;
	}
	else
	{
		rear->next = np;
	}
	rear = np;
}
void order::close_order()
{
	int x;
	if (front == NULL)
	{
		cout << "Order queue is empty now.." << endl;
	}
	else
	{
		cout << "Recently deleted order details:" << endl;
		cout << "Customer Name:" << front->cust_name << endl;
		cout << "Customer Order No:" << front->order_no << endl;
		cout << "Total price:" << front->price << endl;
		if (front == rear)
		{
			front = rear = NULL;
		}
		else
		{
			front = front->next;
		}
	}
}
void order::display_order()
{
	int i;
	struct node* t = front;
	if (front == NULL)
	{
		cout << endl << "Queue is Empty" << endl;
	}
	else
	{
		cout << endl << "Recent customer details in the queue:" << endl;
		do
		{
			cout << endl << "Customer Name:" << t->cust_name << endl;
			cout << "Customer Order No:" << t->order_no << endl;
			cout << "Total price:" << t->price << endl;
			t = t->next;
		} while (t != NULL);
	}
}


int main()
{
	int ch;
	char ch1;
	order ob;
	cout << "COFFEE SHOP ORDER MANAGEMENT SYSTEM" << endl;
	cout << "------------------------------------" << endl;
	do
	{
		cout << endl << "1.Take an Order" << endl;
		cout << "2.Close an Order" << endl;
		cout << "3.Display all order" << endl;
		cout << "4.Exit" << endl;
		cout << "-----------------------" << endl;
		cout << endl << "Enter the option[1,2,3,4]:";
		cin >> ch;

		switch (ch)
		{
			case 1:
				cout << endl << "Item details(To be ordered):" << endl;
				cout << endl << "Small Coffee--->3.99" << endl;
				cout << "Large Coffee--->5.99" << endl;
				cout << "Tea--->3.99" << endl;
				cout << "Blueberry Scone--->1.50" << endl;
				ob.take_order();
				break;

			case 2:
				ob.close_order();
				break;

			case 3:
				ob.display_order();
				break;

			case 4:
				exit;
				break;

			default: cout << "Invalid choice[choose from option 1,2,3,4]";
		}
		cout << endl << "Want to continue[Y/y]:";
		cin >> ch1;
	} while (ch1 == 'Y' || ch1 == 'y');
}