#include <iostream> 
#include <string> 
 
using namespace std; 
 
class Node  
{ 
public: 
    string key; 
    int value; 
    Node *previous; 
    Node *next; 
 
    Node(string k,int v)  
    { 
        key=k; 
        value=v; 
        previous=NULL; 
        next=NULL; 
    } 
}; 
 
class LRUCache  
{ 
private: 
    Node *head; 
    int capacity; 
    int count; 
 
    // Function to search the node using key 
    Node* search(string key)  
    { 
        Node *temp=head; 
        while(temp!=NULL) //Meaning that if the list is not empty. It will execute the body of the while loop. 
        { 
            if(temp->key==key) 
                return temp; 
            temp=temp->next; 
        } 
        return NULL; 
    } 
 
    // Move a target node to the head of the list (Most Recently Used position) 
    void moveToFront(Node *temp)  
    { 
        // If node is already head, no pointer adjustment needed 
        if (temp == head) 
            return; 
 
        // Unlink temp from its current position in the list 
        if (temp->previous != NULL) 
            temp->previous->next = temp->next; 
 
        if (temp->next != NULL) 
            temp->next->previous = temp->previous; 
 
        // Attach temp to the front of the list 
        temp->previous = NULL; 
        temp->next = head; 
        head->previous = temp; 
         
        // Update head pointer to point to temp 
        head = temp; 
    } 
 
    // Remove the last node (Least Recently Used item at the end of the list) 
    void removeLast()  
    { 
        if (head == NULL) 
            return; 
 
        Node *temp = head; 
 
        // Handle single-node list case 
        if (head->next == NULL)  
        { 
            head = NULL; 
        }  
        else  
        { 
            // Traverse to find the last node 
            while (temp->next != NULL)  
            { 
                temp = temp->next; 
            } 
            // Disconnect the last node from the list 
            temp->previous->next = NULL; 
        } 
 
        delete temp; 
        count--; 
    } 
 
public: 
    LRUCache(int size)  
    { 
        head = NULL; 
        capacity = size; 
        count = 0; 
    } 
 
    void put(string key, int value)  
    { 
        Node *temp = search(key); 
 
        // Update value and move to front if key already exists 
        if (temp != NULL)  
        { 
            temp->value = value; 
            moveToFront(temp); 
            cout << "Item updated." << endl; 
            return; 
        } 
 
        // Remove least recently used item if capacity limit reached 
        if (count == capacity)  
        { 
            removeLast(); 
        } 
 
        // Create new node and place it at the front of the list 
        Node *newNode = new Node(key, value); 
        newNode->next = head; 
 
        if (head != NULL)  
        { 
            head->previous = newNode; 
        } 
 
        head = newNode; 
        count++; 
 
        cout << "Item added." << endl; 
    } 
 
    // Retrieve value for key and mark node as recently used 
    bool get(string key, int &value)  
    { 
        Node *temp = search(key); 
 
        if (temp == NULL) 
            return false; 
 
        moveToFront(temp); 
        value = temp->value; 
        return true; 
    } 
 
    void display()  
    { 
        if (head == NULL)  
        { 
            cout << "Cache is empty." << endl; 
            return; 
        } 
 
        Node *temp = head; 
        while (temp != NULL)  
        { 
            cout << "[" << temp->key << ": " << temp->value << "] "; 
            temp = temp->next; 
        } 
        cout << endl; 
    } 
 
    void displaySize()  
    { 
        cout << "Cache size: " << count << endl; 
    } 
 
    ~LRUCache()  
    { 
        Node *temp = head; 
        while (temp != NULL)  
        { 
            Node *nextNode = temp->next; 
            delete temp; 
            temp = nextNode; 
        } 
    } 
}; 
 
int main()  
{ 
    int capacity, choice, value; 
    string key; 
 
    cout << "Enter cache capacity: "; 
    cin >> capacity; 
 
    if (capacity <= 0)  
    { 
        cout << "Capacity must be greater than zero." << endl; 
        return 0; 
    } 
 
    LRUCache cache(capacity); 
 
    do  
    { 
        cout << endl << "1. Put item" << endl; 
        cout << "2. Get item" << endl; 
        cout << "3. Display cache" << endl; 
        cout << "4. Display size" << endl; 
        cout << "5. Exit" << endl; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        if (choice == 1)  
        { 
            cout << "Enter key: "; 
            cin >> key; 
            cout << "Enter value: "; 
            cin >> value; 
            cache.put(key, value); 
        } 
        else if (choice == 2)  
        { 
            cout << "Enter key: "; 
            cin >> key; 
            if (cache.get(key, value)) 
                cout << "Value: " << value << endl; 
            else 
                cout << "Item not found." << endl; 
        } 
        else if (choice == 3)  
        { 
            cache.display(); 
        } 
        else if (choice == 4)  
        { 
            cache.displaySize(); 
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