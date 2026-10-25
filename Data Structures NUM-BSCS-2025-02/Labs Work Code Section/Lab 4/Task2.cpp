#include <iostream> 
using namespace std; 
 
struct Node 
{ 
    int data; 
    Node *next; 
    Node *prev; 
}; 
 
Node *head = NULL; 
 
void insertBeginning(int value) 
{ 
    Node *newNode = new Node; 
 
    newNode->data = value; 
 
    if(head == NULL) 
    { 
        head = newNode; 
 
        newNode->next = head; 
        newNode->prev = head; 
    } 
    else 
    { 
        Node *last = head->prev; 
 
        newNode->next = head; 
        newNode->prev = last; 
 
        last->next = newNode; 
        head->prev = newNode; 
 
        head = newNode; 
    } 
} 
 
void insertEnd(int value) 
{ 
    Node *newNode = new Node; 
 
    newNode->data = value; 
 
    if(head == NULL) 
    { 
        head = newNode; 
 
        newNode->next = head; 
        newNode->prev = head; 
    } 
    else 
    { 
        Node *last = head->prev; 
 
        newNode->next = head; 
        newNode->prev = last; 
 
        last->next = newNode; 
        head->prev = newNode; 
    } 
} 
 
void insertAfter(int searchValue, int value) 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    Node *temp = head; 
 
    do 
    { 
        if(temp->data == searchValue) 
        { 
            Node *newNode = new Node; 
 
            newNode->data = value; 
 
            newNode->next = temp->next; 
            newNode->prev = temp; 
 
            temp->next->prev = newNode; 
            temp->next = newNode; 
 
            return; 
        } 
 
        temp = temp->next; 
 
    } while(temp != head); 
 
    cout << "Node not found." << endl; 
} 
 
void traverse() 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    Node *temp = head; 
 
    do 
    { 
        cout << temp->data << " "; 
        temp = temp->next; 
 
    } while(temp != head); 
 
    cout << endl; 
} 
 
void deleteBeginning() 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    if(head->next == head) 
    { 
        delete head; 
        head = NULL; 
        return; 
    } 
 
    Node *last = head->prev; 
    Node *deleteNode = head; 
 
    head = head->next; 
 
    head->prev = last; 
    last->next = head; 
 
    delete deleteNode; 
} 
 
void deleteEnd() 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    if(head->next == head) 
    { 
        delete head; 
        head = NULL; 
        return; 
    } 
 
    Node *last = head->prev; 
    Node *secondLast = last->prev; 
 
    secondLast->next = head; 
    head->prev = secondLast; 
 
    delete last; 
} 
 
void deleteNode(int value) 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    Node *temp = head; 
 
    do 
    { 
        if(temp->data == value) 
        { 
            if(temp == head) 
            { 
                deleteBeginning(); 
                return; 
            } 
 
            temp->prev->next = temp->next; 
            temp->next->prev = temp->prev; 
 
            delete temp; 
 
            return; 
        } 
 
        temp = temp->next; 
 
    } while(temp != head); 
 
    cout << "Value not found." << endl; 
} 
 
void search(int value) 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    Node *temp = head; 
 
    do 
    { 
        if(temp->data == value) 
        { 
            cout << "Value found." << endl; 
            return; 
        } 
 
        temp = temp->next; 
 
    } while(temp != head); 
 
    cout << "Value not found." << endl; 
} 
 
void update(int oldValue, int newValue) 
{ 
    if(head == NULL) 
    { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    Node *temp = head; 
 
    do 
    { 
        if(temp->data == oldValue) 
        { 
            temp->data = newValue; 
 
            cout << "Value updated." << endl; 
            return; 
        } 
 
        temp = temp->next; 
 
    } while(temp != head); 
 
    cout << "Value not found." << endl; 
} 
 
int main() 
{ 
    int choice; 
    int value; 
    int searchValue; 
    int newValue; 
 
    do 
    { 
        cout << endl; 
        cout << "***** Doubly Circular Linked List *****" << endl; 
        cout << "1. Insert at Beginning" << endl; 
        cout << "2. Insert at End" << endl; 
        cout << "3. Insert After Given Node" << endl; 
        cout << "4. Traverse" << endl; 
        cout << "5. Delete Beginning" << endl; 
        cout << "6. Delete End" << endl; 
        cout << "7. Delete Any Node" << endl; 
        cout << "8. Search" << endl; 
        cout << "9. Update" << endl; 
        cout << "10. Exit" << endl; 
 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        if(choice == 1) 
        { 
            cout << "Enter value: "; 
            cin >> value; 
            insertBeginning(value); 
        } 
        else if(choice == 2) 
        { 
            cout << "Enter value: "; 
            cin >> value; 
            insertEnd(value); 
        } 
        else if(choice == 3) 
        { 
            cout << "Enter node after which you want to insert: "; 
            cin >> searchValue; 
 
            cout << "Enter new value: "; 
            cin >> value; 
 
            insertAfter(searchValue, value); 
        } 
        else if(choice == 4) 
        { 
            traverse(); 
        } 
        else if(choice == 5) 
        { 
            deleteBeginning(); 
        } 
        else if(choice == 6) 
        { 
            deleteEnd(); 
        } 
        else if(choice == 7) 
        { 
            cout << "Enter value to delete: "; 
            cin >> value; 
 
            deleteNode(value); 
        } 
        else if(choice == 8) 
        { 
            cout << "Enter value to search: "; 
            cin >> value; 
 
            search(value); 
        } 
        else if(choice == 9) 
        { 
            cout << "Enter old value: "; 
            cin >> value; 
 
            cout << "Enter new value: "; 
            cin >> newValue; 
 
            update(value, newValue); 
        } 
        else if(choice == 10) 
        { 
            cout << "Program terminated." << endl; 
        } 
        else 
        { 
            cout << "Invalid choice." << endl; 
        } 
 
    } while(choice != 10); 
 
return 0; 
}