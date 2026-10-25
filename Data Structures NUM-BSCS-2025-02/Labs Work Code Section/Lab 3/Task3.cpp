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

    void DeleteHead()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << "Head node deleted." << endl;
        }
    }

    void DeleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;

            cout << "Last node deleted." << endl;
        }
        else
        {
            Node* temp = head;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }

            delete temp->next;
            temp->next = NULL;

            cout << "Last node deleted." << endl;
        }
    }

    void DeleteAtPosition(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (position == 1)
        {
            DeleteHead();
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1 && temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            cout << "Position out of range." << endl;
        }
        else
        {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;

            cout << "Node at position " << position << " deleted." << endl;
        }
    }
};

int main()
{
    LinkedList list;

    int choice;
    int value;
    int position;

    do
    {
        cout << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Traverse List" << endl;
        cout << "3. Delete Head Node" << endl;
        cout << "4. Delete End Node" << endl;
        cout << "5. Delete at Given Position" << endl;
        cout << "6. Exit" << endl;

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
            list.Traverse();
        }
        else if (choice == 3)
        {
            list.DeleteHead();
        }
        else if (choice == 4)
        {
            list.DeleteEnd();
        }
        else if (choice == 5)
        {
            cout << "Enter position to delete: ";
            cin >> position;

            list.DeleteAtPosition(position);
        }
        else if (choice == 6)
        {
            cout << "Program ended." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}

