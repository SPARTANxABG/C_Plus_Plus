#include <string>
#include <iostream>

using namespace std;

class EmployeeInfo
{
	public:
		int id;
		string name;
};

struct node
{
	EmployeeInfo info;
	node* left;
	node* right;
};

class btree
{
	public:
		btree();
		~btree();
		void insert(EmployeeInfo key);
		node* search(int key);
		void destroy_tree();

	private:
		void destroy_tree(node* leaf);
		void insert(EmployeeInfo key, node* leaf);
		node* search(int key, node* leaf);
		node* root;
};

btree::btree()
{
	root = NULL;
}

void btree::destroy_tree(node* leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(EmployeeInfo key, node* leaf)
{
	if (key.id < leaf->info.id)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);

		else
		{
			leaf->left = new node;
			leaf->left->info = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}

	else if (key.id >= leaf->info.id)
	{
		if (leaf->right != NULL)
		insert(key, leaf->right);

		else
		{
			leaf->right = new node;
			leaf->right->info = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node* btree::search(int key, node* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->info.id)
			return leaf;

		if (key < leaf->info.id)
			return search(key, leaf->left);

		else
			return search(key, leaf->right);
	}
	else return NULL;
}

node* btree::search(int key)
{
	return search(key, root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void btree::insert(EmployeeInfo key)
{
	if (root != NULL)
	insert(key, root);

	else
	{
		root = new node;
		root->info = key;
		root->left = NULL;
		root->right = NULL;
	}
}

int main()
{
	EmployeeInfo info[10];
	btree* bt = new btree();

	info[0].id = 1015;
	info[0].name = "Sam Kennedy";
	info[1].id = 1277;
	info[1].name = "Connor Mills";
	info[2].id = 1668;
	info[2].name = "Ty Watkins";
	info[3].id = 1497;
	info[3].name = "Yasmin Lane";
	info[4].id = 1016;
	info[4].name = "Ashley Chapman";
	info[5].id = 2829;
	info[5].name = "Vic Conrad";
	info[6].id = 1049;
	info[6].name = "Ryan Dawson";
	info[7].id = 1504;
	info[7].name = "Isabella Wright";
	info[8].id = 2111;
	info[8].name = "Charlie Riddle";
	info[9].id = 1850;
	info[9].name = "Crystal Boyer";

	int i;

	for (i = 0; i < 10; i++)
	{
		bt->insert(info[i]);
	}

	int id;
	cout << "Please enter an Employee ID number: ";
	cin >> id;

	if (bt->search(id) == NULL)
	cout << id << "\n\nEmployee ID not found!" << endl;

	else
	cout << id << "\n\nEmployee ID found!" << endl << "\nEmployee name is: " << (bt->search(id))->info.name << endl;

	return 1;
}