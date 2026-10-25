 
#include <iostream> 
#include <string> 
 
using namespace std; 
 
// Custom helper function to convert integer ID to string using only standard logic 
string intToString(int number) 
{ 
    if (number == 0) 
        return "0"; 
 
    string result = ""; 
    bool isNegative = false; 
 
    if (number < 0) 
    { 
        isNegative = true; 
        number = -number; 
    } 
 
    while (number > 0) 
    { 
        char digit = '0' + (number % 10); 
        result = digit + result; 
        number /= 10; 
    } 
 
    if (isNegative) 
        result = "-" + result; 
 
    return result; 
} 
 
// Node structure representing a single block in the singly linked list 
class Node 
{ 
public: 
    int blockID; 
    string transaction; 
    string timeStamp; 
    string prevHash; 
    string currentHash; 
    Node* next; 
 
    Node(int id, string trans, string previous, string timeStr) 
    { 
        blockID = id; 
        transaction = trans; 
        timeStamp = timeStr; 
        prevHash = previous; 
        // Hash calculated from block data fields: ID, transaction, timestamp, and previous hash 
        currentHash = intToString(id) + transaction + timeStamp + prevHash; 
        next = NULL; 
    } 
}; 
 
class Blockchain 
{ 
private: 
    Node* head; 
    Node* tail; 
 
public: 
    Blockchain() 
    { 
        head = NULL; 
        tail = NULL; 
    } 
 
    void addBlock() 
    { 
        int id; 
        string trans; 
        string timeStr; 
        string previous = "0"; 
 
        cout << "Enter Block ID: "; 
        cin >> id; 
 
        cout << "Enter Transaction: "; 
        cin >> ws; 
        getline(cin, trans); 
 
        cout << "Enter Timestamp: "; 
        getline(cin, timeStr); 
 
        // If list is not empty, get the hash of the last block (tail) 
        if (tail != NULL) 
            previous = tail->currentHash; 
 
        Node* newNode = new Node(id, trans, previous, timeStr); 
 
        // Case 1: Empty linked list (inserting the first block) 
        if (head == NULL) 
        { 
            head = newNode; 
            tail = newNode; 
        } 
        // Case 2: Append new node to the end of the list and update tail pointer 
        else 
        { 
            tail->next = newNode; 
            tail = newNode; 
        } 
 
        cout << "Block added successfully!" << endl; 
    } 
 
    // Displays all blocks by traversing from head to end of the singly linked list 
    void display() 
    { 
        if (head == NULL) 
        { 
            cout << "Blockchain is empty!" << endl; 
            return; 
        } 
 
        Node* current = head; 
 
        while (current != NULL) 
        { 
            cout << endl; 
            cout << "Block ID: " << current->blockID << endl; 
            cout << "Transaction: " << current->transaction << endl; 
            cout << "Timestamp: " << current->timeStamp << endl; 
            cout << "Previous Hash: " << current->prevHash << endl; 
            cout << "Current Hash: " << current->currentHash << endl; 
 
            current = current->next; // Advance to the next node in the chain 
        } 
    } 
 
    // Searches linearly through the chain for a specific transaction 
    void searchTransaction() 
    { 
        string trans; 
        cout << "Enter Transaction to search: "; 
        cin >> ws; 
        getline(cin, trans); 
 
        Node* current = head; 
 
        while (current != NULL) 
        { 
            if (current->transaction == trans) 
            { 
                cout << "Transaction found in Block " << current->blockID << endl; 
                return; 
            } 
            current = current->next; 
        } 
 
        cout << "Transaction not found!" << endl; 
    } 
 
    // Deletes a block by ID and manages head pointer correctly 
    void deleteBlock() 
    { 
        if (head == NULL) 
        { 
            cout << "Blockchain is empty!" << endl; 
            return; 
        } 
 
        int id; 
        cout << "Enter Block ID to delete: "; 
        cin >> id; 
 
        Node* current = head; 
        Node* prev = NULL; 
 
        // Traverse to locate target node and keep track of previous node 
        while (current != NULL && current->blockID != id) 
        { 
            prev = current; 
            current = current->next; 
        } 
 
        if (current == NULL) 
        { 
            cout << "Block not found!" << endl; 
            return; 
        } 
 
        // Case 1: Deleting the head node 
        if (prev == NULL) 
        { 
            head = current->next; 
        } 
        // Case 2: Deleting a middle or tail node 
        else 
        { 
            prev->next = current->next; // Unlink node from list chain 
        } 
 
        // Case 3: If deleted node was the tail, update tail pointer to previous node 
        if (current == tail) 
        { 
            tail = prev; 
        } 
 
        delete current; 
        cout << "Block deleted successfully!" << endl; 
    } 
 
    // Verifies integrity of hashes and pointer links across all blocks 
    void verifyChain() 
    { 
        if (head == NULL) 
        { 
            cout << "Blockchain is empty!" << endl; 
            return; 
        } 
 
        Node* current = head; 
        string expectedPrev = "0"; 
 
        while (current != NULL) 
        { 
            // Re-calculate expected hash for current block using custom intToString 
            string expectedHash = intToString(current->blockID) + current->transaction + current->timeStamp + current
>prevHash; 
 
            // Check if current block hash was tampered with or link chain is broken 
            if (current->currentHash != expectedHash || current->prevHash != expectedPrev) 
            { 
                cout << "Blockchain has been modified or corrupted!" << endl; 
                return; 
            } 
 
            expectedPrev = current->currentHash; 
            current = current->next; 
        } 
 
        cout << "Blockchain is valid!" << endl; 
    } 
 
    ~Blockchain() 
    { 
        Node* current = head; 
 
        while (current != NULL) 
        { 
            Node* temp = current; 
            current = current->next; 
            delete temp; 
        } 
    } 
}; 
 
int main() 
{ 
    Blockchain chain; 
    int choice; 
 
    do 
    { 
        cout << endl; 
        cout << "1. Add Block" << endl; 
        cout << "2. Display Blockchain" << endl; 
        cout << "3. Search Transaction" << endl; 
        cout << "4. Delete Block" << endl; 
        cout << "5. Verify Blockchain" << endl; 
        cout << "6. Exit" << endl; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        if (choice == 1) 
            chain.addBlock(); 
        else if (choice == 2) 
            chain.display(); 
        else if (choice == 3) 
            chain.searchTransaction(); 
        else if (choice == 4) 
            chain.deleteBlock(); 
        else if (choice == 5) 
            chain.verifyChain(); 
        else if (choice == 6) 
            cout << "Exiting..." << endl; 
        else 
            cout << "Invalid choice!" << endl; 
 
    } while (choice != 6); 
 
    return 0; 
} 