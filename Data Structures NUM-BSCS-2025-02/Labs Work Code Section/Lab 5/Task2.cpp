#include<iostream> 
#include<string> 
using namespace std; 
 
class Node 
{ 
public: 
    string URL; 
    string Page_Title; 
    string Visit_Time; 
    Node* previous; 
    Node* next; 
 
    Node(string url, string title, string time) 
    { 
        URL = url; 
        Page_Title = title; 
        Visit_Time = time; 
        previous = NULL; 
        next = NULL; 
    } 
}; 
 
class Browser_History 
{ 
private: 
    Node* head; 
    Node* current; 
 
public: 
    Browser_History() 
    { 
        head = NULL; 
        current = NULL; 
    } 
 
    void VisitNewPage(string url, string title, string time) 
    { 
        Node* newNode = new Node(url, title, time); 
 
        if(head == NULL) 
        { 
            head = newNode; 
            current = newNode; 
        } 
        else 
        { 
            Node* temp = current->next; 
 
            while(temp != NULL) 
            { 
                Node* deleteNode = temp; 
                temp = temp->next; 
                delete deleteNode; 
            } 
 
            current->next = NULL; 
 
            current->next = newNode; 
            newNode->previous = current; 
 
            current = newNode; 
        } 
 
        cout << "Webpage visited successfully." << endl; 
        cout << "Current Page: " << current->Page_Title << endl; 
    } 
 
    void GoBack() 
    { 
        if(current == NULL) 
        { 
            cout << "Browser history is empty." << endl; 
        } 
        else if(current->previous == NULL) 
        { 
            cout << "No previous webpage exists." << endl; 
        } 
        else 
        { 
            current = current->previous; 
 
            cout << "Moved backward successfully." << endl; 
            cout << "Current Page: " << current->Page_Title << endl; 
            cout << "URL: " << current->URL << endl; 
        } 
    } 
 
    void GoForward() 
    { 
        if(current == NULL) 
        { 
            cout << "Browser history is empty." << endl; 
        } 
        else if(current->next == NULL) 
        { 
            cout << "No next webpage exists." << endl; 
        } 
        else 
        { 
            current = current->next; 
 
            cout << "Moved forward successfully." << endl; 
            cout << "Current Page: " << current->Page_Title << endl; 
            cout << "URL: " << current->URL << endl; 
        } 
    } 
 
    void DisplayHistory() 
    { 
        if(head == NULL) 
        { 
            cout << "Browser history is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        cout << endl << "===== BROWSING HISTORY =====" << endl; 
 
        while(temp != NULL) 
        { 
            cout << "Page Title: " << temp->Page_Title << endl; 
            cout << "URL: " << temp->URL << endl; 
            cout << "Visit Time: " << temp->Visit_Time << endl; 
 
            if(temp == current) 
            { 
                cout << "Status: Current Page" << endl; 
            } 
 
            cout << "------------------------" << endl; 
 
            temp = temp->next; 
        } 
    } 
 
    void DeleteWebpage(string url) 
    { 
        if(head == NULL) 
        { 
            cout << "Browser history is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        while(temp != NULL) 
        { 
            if(temp->URL == url) 
            { 
                Node* nextNode = temp->next; 
                Node* previousNode = temp->previous; 
 
                if(previousNode != NULL) 
                { 
                    previousNode->next = nextNode; 
                } 
                else 
                { 
                    head = nextNode; 
                } 
 
                if(nextNode != NULL) 
                { 
                    nextNode->previous = previousNode; 
                } 
 
                if(current == temp) 
                { 
                    if(nextNode != NULL) 
                    { 
                        current = nextNode; 
                    } 
                    else 
                    { 
                        current = previousNode; 
                    } 
                } 
 
                delete temp; 
 
                cout << "Webpage deleted successfully." << endl; 
                return; 
            } 
 
            temp = temp->next; 
        } 
 
        cout << "Given URL does not exist." << endl; 
    } 
 
    void SearchURL(string url) 
    { 
        if(head == NULL) 
        { 
            cout << "Browser history is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        while(temp != NULL) 
        { 
            if(temp->URL == url) 
            { 
                cout << "Webpage found!" << endl; 
                cout << "URL: " << temp->URL << endl; 
                cout << "Page Title: " << temp->Page_Title << endl; 
                cout << "Visit Time: " << temp->Visit_Time << endl; 
                return; 
            } 
 
            temp = temp->next; 
        } 
 
        cout << "Given URL not found." << endl; 
    } 
 
    void DisplayNewestToOldest() 
    { 
        if(head == NULL) 
        { 
            cout << "Browser history is empty." << endl; 
            return; 
        } 
 
        Node* temp = current; 
 
        while(temp->next != NULL) 
        { 
            temp = temp->next; 
        } 
 
        cout << endl << "===== NEWEST TO OLDEST =====" << endl; 
 
        while(temp != NULL) 
        { 
            cout << "Page Title: " << temp->Page_Title << endl; 
            cout << "URL: " << temp->URL << endl; 
            cout << "Visit Time: " << temp->Visit_Time << endl; 
            cout << "------------------------" << endl; 
 
            temp = temp->previous; 
        } 
    } 
 
    void ClearHistory() 
    { 
        if(head == NULL) 
        { 
            cout << "Browser history is already empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        while(temp != NULL) 
        { 
            Node* deleteNode = temp; 
            temp = temp->next; 
            delete deleteNode; 
        } 
 
        head = NULL; 
        current = NULL; 
 
        cout << "Browser history cleared successfully." << endl; 
    } 
}; 
 
void menu() 
{ 
    cout << endl; 
    cout << "===== WEB BROWSER NAVIGATION =====" << endl; 
    cout << "1. Visit a new webpage." << endl; 
    cout << "2. Go Back." << endl; 
    cout << "3. Go Forward." << endl; 
    cout << "4. Display complete browsing history." << endl; 
    cout << "5. Delete a particular webpage." << endl; 
    cout << "6. Search a URL." << endl; 
    cout << "7. Display history from newest to oldest." << endl; 
    cout << "8. Clear browser history." << endl; 
    cout << "9. Exit." << endl; 
} 
 
void getPageInput(string &url, string &title, string &time) 
{ 
    cout << "Enter webpage URL: "; 
    cin>>url; 
 
    cout << "Enter page title: "; 
    cin>>title; 
 
    cout << "Enter visit time: "; 
    cin>>time; 
} 
 
int main() 
{ 
    Browser_History browser; 
 
    int choice; 
    string url, title, time; 
 
    do 
    { 
        menu(); 
 
        cout << "Enter your choice please: "; 
        cin >> choice; 
 
        cout << endl; 
 
        if(choice == 1) 
        { 
            getPageInput(url, title, time); 
            browser.VisitNewPage(url, title, time); 
        } 
        else if(choice == 2) 
        { 
            browser.GoBack(); 
        } 
        else if(choice == 3) 
        { 
            browser.GoForward(); 
        } 
        else if(choice == 4) 
        { 
            browser.DisplayHistory(); 
        } 
        else if(choice == 5) 
        { 
            cout << "Enter URL to delete: "; 
            cin.ignore(); 
            getline(cin, url); 
 
            browser.DeleteWebpage(url); 
        } 
        else if(choice == 6) 
        { 
            cout << "Enter URL to search: "; 
            cin.ignore(); 
            getline(cin, url); 
 
            browser.SearchURL(url); 
        } 
        else if(choice == 7) 
        { 
            browser.DisplayNewestToOldest(); 
        } 
        else if(choice == 8) 
        { 
            browser.ClearHistory(); 
        } 
        else if(choice == 9) 
        { 
            cout << "Exiting browser history manager." << endl; 
        } 
        else 
        { 
            cout << "Invalid choice. Try again." << endl; 
        } 
 
} while(choice != 9); 
return 0; 
}