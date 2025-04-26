//AOlivares_Lab6

#include <stdio.h>
#include <iostream>

using namespace std;

template<class T>
struct node 
{
    node<T>* next;
    T data;
};

template<class T>
class LinkedList
{
    public:
     node<T>* head;
     node<T>* last;
      LinkedList<T>() {
          head = NULL;
          last = NULL;
    }

    void addSorted(T data) 
    {
        if (head == NULL) 
        {
            head = new node<T>;
            head->data = data;
            head->next = NULL;
            last = head;
        }

        else 
        {
            if (last == head && head->data < data) 
            {
                last = new node<T>;
                last->data = data;
                last->next = NULL;
                head->next = last;
            }

            else if (last == head && head->data >= data) 
            {
                last = new node<T>;
                last->data = data;
                last->next = head;
                head = last;
            }

            else 
            {
                node<T>* curr = this->head;
                node<T>* temp = new node<T>;
                temp->data = data;
                temp->next = NULL;

                if (curr->data > temp->data)
                {
                    temp->next = curr;
                    this->head = temp;
                    return;
                }

                while (curr->next != NULL && curr->next->data < temp->data) 
                {
                    curr = curr->next;
                }

                temp->next = curr->next;
                curr->next = temp;
            }
        }
    }

    void display() 
    {
        node<T>* curr = this->head;

        while (curr != NULL) 
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << endl;

    }

    int length() 
    {
        int count = 0;
        node<T>* curr = this->head;

        while (curr != NULL) 
        {
            curr = curr->next;
            count++;
        }
        return count;
    }


    void deleteNode(T data) 
    {
        node<T>* curr = this->head;
        node<T>* prev = NULL;

        if (curr != NULL && curr->data == data) 
        {
            head = curr->next;
            delete curr;
            return;
        }

        else 
        {
            while (curr != NULL && curr->data != data) 
            {
                prev = curr;
                curr = curr->next;
            }

            if (curr == NULL) 
            {
                cout << "Value not found." << endl;
                return;
            }

            prev->next = curr->next;
            delete curr;
        }
    }

};

int main(int argc, char const* argv[])
{
    LinkedList<double> DOUBLE_LIST;
    DOUBLE_LIST.addSorted(13.37);
    DOUBLE_LIST.addSorted(42.01);
    DOUBLE_LIST.addSorted(78.25);
    DOUBLE_LIST.addSorted(16.68);
    DOUBLE_LIST.addSorted(43.57);
    DOUBLE_LIST.addSorted(64.00);
    DOUBLE_LIST.addSorted(54.57);
    DOUBLE_LIST.addSorted(10.78);
    DOUBLE_LIST.addSorted(99.99);
    DOUBLE_LIST.addSorted(57.77);
    DOUBLE_LIST.addSorted(80.01);
    DOUBLE_LIST.addSorted(34.82);
    DOUBLE_LIST.addSorted(29.44);

    while (true) 
    {
        int input;

        cout << "\nLinked List Options: \n";
        cout << "\n1) Display list contents";
        cout << "\n2) Display list lenght";
        cout << "\n3) Insert an element";
        cout << "\n4) Remove an element";
        cout << "\n5) Exit Menu" << endl;
        cin >> input;
        cout << "\n";

        switch (input) 
        {
            case 1:
               cout << "Current List Contents:\n";
               DOUBLE_LIST.display();
               break;

            case 2:  
               cout << "Current List Length: " << DOUBLE_LIST.length() << endl;
               break;

            case 3:  
               cout << "Enter a double value to add to list" << endl;
               double val;
               cin >> val;
               DOUBLE_LIST.addSorted(val);
               cout << "Value added" << endl;
               DOUBLE_LIST.display();
               break;

            case 4:
               cout << "Enter a value to be deleted from list" << endl;
               double valDel;
               cin >> valDel;
               DOUBLE_LIST.deleteNode(valDel);
               DOUBLE_LIST.display();
               break;

            case 5: 
               break;

            default: 
               break;
        }
        
        if (input == 5) 
        {
            break;
        }
    }
}