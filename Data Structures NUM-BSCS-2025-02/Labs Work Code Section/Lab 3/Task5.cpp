#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;

public:

    LinkedList()
    {
        head = NULL;
    }

    void InsertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void Traverse()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            Node* temp = head;

            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }

    void UpdateAtPosition(int position, int newValue)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position && temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
        {
            cout << "Position out of range." << endl;
        }
        else
        {
            temp->data = newValue;
            cout << "Node at position " << position << " updated to " << newValue << "." << endl;
        }
    }
};

int main()
{
    LinkedList list;

    int choice;
    int value;
    int position;
    int newValue;

    do
    {
        cout << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Traverse List" << endl;
        cout << "3. Update Node at Position" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            list.InsertAtEnd(value);
        }
        else if (choice == 2)
        {
            list.Traverse();
        }
        else if (choice == 3)
        {
            cout << "Enter position to update: ";
            cin >> position;

            cout << "Enter new value: ";
            cin >> newValue;

            list.UpdateAtPosition(position, newValue);
        }
        else if (choice == 4)
        {
            cout << "Program ended." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}

