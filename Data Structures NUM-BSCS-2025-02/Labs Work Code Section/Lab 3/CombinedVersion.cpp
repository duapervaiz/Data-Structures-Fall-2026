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

    void InsertAtPosition(int position, int value)
    {
        if (position <= 0)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1)
        {
            InsertAtBeginning(value);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (count < position - 1 && temp != NULL)
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
            Node* newNode = new Node(value);

            newNode->next = temp->next;
            temp->next = newNode;
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

            cout << "First node deleted." << endl;
        }
    }

    void DeleteAtPosition(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (position <= 0)
        {
            cout << "Invalid position." << endl;
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

    void Search(int key)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Value " << key << " found at position " << position << "." << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Value " << key << " not found in the list." << endl;
    }

    void UpdateAtPosition(int position, int newValue)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (position <= 0)
        {
            cout << "Invalid position." << endl;
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

            cout << "Node at position " << position << " updated." << endl;
        }
    }
};

int main()
{
    LinkedList list;

    int choice;
    int value;
    int position;
    int key;
    int newValue;

    do
    {
        cout << endl;
        cout << "1. Insert at first" << endl;
        cout << "2. Insert at last" << endl;
        cout << "3. Insert at any position" << endl;
        cout << "4. Delete at first" << endl;
        cout << "5. Delete at any position" << endl;
        cout << "6. Delete at end" << endl;
        cout << "7. Traverse the list" << endl;
        cout << "8. Search a node" << endl;
        cout << "9. Update a node" << endl;
        cout << "10. Exit" << endl;

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
            cout << "Enter position: ";
            cin >> position;

            cout << "Enter value: ";
            cin >> value;

            list.InsertAtPosition(position, value);
        }
        else if (choice == 4)
        {
            list.DeleteHead();
        }
        else if (choice == 5)
        {
            cout << "Enter position to delete: ";
            cin >> position;

            list.DeleteAtPosition(position);
        }
        else if (choice == 6)
        {
            list.DeleteEnd();
        }
        else if (choice == 7)
        {
            list.Traverse();
        }
        else if (choice == 8)
        {
            cout << "Enter value to search: ";
            cin >> key;

            list.Search(key);
        }
        else if (choice == 9)
        {
            cout << "Enter position to update: ";
            cin >> position;

            cout << "Enter new value: ";
            cin >> newValue;

            list.UpdateAtPosition(position, newValue);
        }
        else if (choice == 10)
        {
            cout << "Program ended." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 10);

    return 0;
}

