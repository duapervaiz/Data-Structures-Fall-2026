#include <iostream> 
#include <string> 
using namespace std; 
class Prompt 
{ 
public: 
    int id; 
    string text; 
    Prompt *next; 
 
    Prompt(int promptID, string promptText) 
    { 
        id = promptID; 
        text = promptText; 
        next = NULL; 
    } 
}; 
 
// Application class using a Singly Linked List to manage prompt history 
class PromptHistory 
{ 
private: 
    Prompt *head; 
 
public: 
    PromptHistory() 
    { 
        head = NULL; 
    } 
 
    // Operation 1: Insertion - Add prompt to the end of the linked list 
    void addPrompt(int id, string text) 
    { 
        Prompt *newPrompt = new Prompt(id, text); 
 
        // Case 1: Empty list (new prompt becomes head) 
        if (head == NULL) 
        { 
            head = newPrompt; 
        } 
        // Case 2: Traverse to the end and append new node 
        else 
        { 
            Prompt *current = head; 
 
            while (current->next != NULL) 
                current = current->next; 
 
            // Link the last node's next pointer to the new node 
            current->next = newPrompt; 
        } 
 
        cout << "Prompt saved." << endl; 
    } 
 
    // Operation 2: Deletion - Delete a prompt by ID (handles head, middle, tail, missing node) 
    void deletePrompt(int id) 
    { 
        Prompt *current = head; 
        Prompt *previous = NULL; 
 
        // Traverse list while searching for target ID and keeping track of previous node 
        while (current != NULL && current->id != id) 
        { 
            previous = current; 
            current = current->next; 
        } 
 
        if (current == NULL) 
        { 
            cout << "Prompt not found." << endl; 
            return; 
        } 
 
        // Case 1: Deleting the head node 
        if (previous == NULL) 
            head = current->next; 
        // Case 2: Deleting middle or tail node -> update previous node's next pointer 
        else 
            previous->next = current->next; 
 
        delete current; 
        cout << "Prompt deleted." << endl; 
    } 
 
    // Operation 3: Search - Linearly search prompt by ID 
    void searchPrompt(int id) 
    { 
        Prompt *current = head; 
 
        while (current != NULL) 
        { 
            if (current->id == id) 
            { 
                cout << "Prompt found: " << current->text << endl; 
                return; 
            } 
            current = current->next; 
        } 
 
        cout << "Prompt not found." << endl; 
    } 
 
    // Operation 4: Traversal - Display full prompt history 
    void displayHistory() 
    { 
        if (head == NULL) 
        { 
            cout << "Prompt history is empty." << endl; 
            return; 
        } 
 
        Prompt *current = head; 
        cout << "Prompt history:" << endl; 
 
        while (current != NULL) 
        { 
            cout << current->id << ": " << current->text << endl; 
            current = current->next; // Advance to next node 
        } 
    } 
 
    ~PromptHistory() 
    { 
        Prompt *current = head; 
 
        while (current != NULL) 
        { 
            Prompt *nextPrompt = current->next; 
            delete current; 
            current = nextPrompt; 
        } 
    } 
}; 
 
int main() 
{ 
    PromptHistory history; 
    int choice, id; 
    string text; 
 
    do 
    { 
        cout << endl << "===== PROMPT HISTORY MENU =====" << endl; 
        cout << "1. Add prompt" << endl; 
        cout << "2. Delete prompt" << endl; 
        cout << "3. Search prompt" << endl; 
        cout << "4. Display history" << endl; 
        cout << "5. Exit" << endl; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        if (choice == 1) 
        { 
            cout << "Enter prompt ID: "; 
            cin >> id; 
 
            cout << "Enter prompt text: "; 
            cin >> ws; // Clear leading whitespace 
            getline(cin, text); 
 
            history.addPrompt(id, text); 
        } 
        else if (choice == 2) 
        { 
            cout << "Enter prompt ID to delete: "; 
            cin >> id; 
            history.deletePrompt(id); 
        } 
        else if (choice == 3) 
        { 
            cout << "Enter prompt ID to search: "; 
            cin >> id; 
            history.searchPrompt(id); 
        } 
        else if (choice == 4) 
            history.displayHistory(); 
        else if (choice == 5) 
            cout << "Program ended." << endl; 
        else 
            cout << "Invalid choice." << endl; 
    } while (choice != 5); 
    return 0; 
} 