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

    void InsertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
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

    void InsertAfterGivenNode(int givenValue, int newValue)
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
                if (temp->data == givenValue)
                {
                    Node* newNode = new Node(newValue);

                    newNode->next = temp->next;
                    temp->next = newNode;

                    return;
                }

                temp = temp->next;
            }

            cout << "Given node not found." << endl;
        }
    }

    void Display()
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
};

int main()
{
    LinkedList list;

    int choice;
    int value;
    int givenValue;

    do
    {
        cout << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Given Node" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            list.InsertAtBeginning(value);
        }
        else if (choice == 2)
        {
            cout << "Enter value: ";
            cin >> value;

            list.InsertAtEnd(value);
        }
        else if (choice == 3)
        {
            cout << "Enter the existing node value: ";
            cin >> givenValue;

            cout << "Enter new node value: ";
            cin >> value;

            list.InsertAfterGivenNode(givenValue, value);
        }
        else if (choice == 4)
        {
            list.Display();
        }
        else if (choice == 5)
        {
            cout << "Program ended." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}


