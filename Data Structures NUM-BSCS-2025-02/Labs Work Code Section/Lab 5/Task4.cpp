#include<iostream> 
#include<string> 
using namespace std; 
 
class Node 
{ 
public: 
    int Request_ID; 
    int User_ID; 
    string Model_Name; 
    int Processing_Time; 
    Node* next; 
 
    Node(int requestID, int userID, string modelName, int time) 
    { 
        Request_ID = requestID; 
        User_ID = userID; 
        Model_Name = modelName; 
        Processing_Time = time; 
        next = NULL; 
    } 
}; 
class Request_Scheduler 
{ 
private: 
    Node* head; 
    Node* current; 
 
public: 
    Request_Scheduler() 
    { 
        head = NULL; 
        current = NULL; 
    } 
 
    void AddRequest(int requestID, int userID, string modelName, int time) 
    { 
        Node* newNode = new Node(requestID, userID, modelName, time); 
 
        if(head == NULL) 
        { 
            head = newNode; 
            newNode->next = head; 
            current = head; 
        } 
        else 
        { 
            Node* temp = head; 
 
            while(temp->next != head) 
            { 
                temp = temp->next; 
            } 
 
            temp->next = newNode; 
            newNode->next = head; 
        } 
 
        cout << "Request added successfully." << endl; 
    } 
 
    void RemoveRequest(int ID) 
    { 
        if(head == NULL) 
        { 
            cout << "Request list is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
        Node* previousNode = NULL; 
 
        do 
        { 
            if(temp->Request_ID == ID) 
            { 
                break; 
            } 
 
            previousNode = temp; 
            temp = temp->next; 
 
        } while(temp != head); 
 
        if(temp->Request_ID != ID) 
        { 
            cout << "Request ID not found." << endl; 
            return; 
        } 
 
        if(temp == head && temp->next == head) 
        { 
            delete temp; 
            head = NULL; 
            current = NULL; 
 
            cout << "Request removed successfully." << endl; 
            return; 
        } 
 
        if(temp == head) 
        { 
            Node* last = head; 
 
            while(last->next != head) 
            { 
                last = last->next; 
            } 
 
            head = head->next; 
            last->next = head; 
        } 
        else 
        { 
            previousNode->next = temp->next; 
        } 
 
        if(current == temp) 
        { 
            current = temp->next; 
        } 
 
        delete temp; 
 
        cout << "Request removed successfully." << endl; 
    } 
 
    void ProcessNextRequest() 
    { 
        if(head == NULL) 
        { 
            cout << "No requests available to process." << endl; 
            return; 
        } 
 
        if(current == NULL) 
        { 
            current = head; 
        } 
 
        cout << "Processing Request..." << endl; 
        cout << "Request ID: " << current->Request_ID << endl; 
        cout << "User ID: " << current->User_ID << endl; 
        cout << "Model Name: " << current->Model_Name << endl; 
        cout << "Processing Time: " << current->Processing_Time << " seconds" << endl; 
 
        cout << "Request processed successfully." << endl; 
 
        current = current->next; 
    } 
 
    void DisplayRequests() 
    { 
        if(head == NULL) 
        { 
            cout << "Request list is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        cout << endl << "===== ACTIVE REQUESTS =====" << endl; 
 
        do 
        { 
            cout << "Request ID: " << temp->Request_ID << endl; 
            cout << "User ID: " << temp->User_ID << endl; 
            cout << "Model Name: " << temp->Model_Name << endl; 
            cout << "Processing Time: " << temp->Processing_Time << " seconds" << endl; 
 
            if(temp == current) 
            { 
                cout << "Status: Next in Queue" << endl; 
            } 
 
            cout << "------------------------" << endl; 
 
            temp = temp->next; 
 
        } while(temp != head); 
    } 
 
    void FindRequest(int ID) 
    { 
        if(head == NULL) 
        { 
            cout << "Request list is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        do 
        { 
            if(temp->Request_ID == ID) 
            { 
                cout << "Request found!" << endl; 
                cout << "Request ID: " << temp->Request_ID << endl; 
                cout << "User ID: " << temp->User_ID << endl; 
                cout << "Model Name: " << temp->Model_Name << endl; 
                cout << "Processing Time: " << temp->Processing_Time << " seconds" << endl; 
                return; 
            } 
 
            temp = temp->next; 
 
        } while(temp != head); 
 
        cout << "Request ID not found." << endl; 
    } 
 
    void SimulateCycles() 
    { 
        if(head == NULL) 
        { 
            cout << "No requests available for simulation." << endl; 
            return; 
        } 
 
        if(current == NULL) 
        { 
            current = head; 
        } 
 
        cout << endl << "===== 10 SCHEDULING CYCLES =====" << endl; 
 
        int cycle = 1; 
 
        while(cycle <= 10) 
        { 
            cout << endl << "Cycle: " << cycle << endl; 
            cout << "Processing Request ID: " << current->Request_ID << endl; 
            cout << "User ID: " << current->User_ID << endl; 
            cout << "Model Name: " << current->Model_Name << endl; 
 
            current = current->next; 
            cycle++; 
        } 
 
        cout << endl << "10 scheduling cycles completed." << endl; 
    } 
}; 
 
void menu() 
{ 
    cout << endl << "===== AI MODEL REQUEST SCHEDULER =====" << endl; 
    cout << "1. Add a request." << endl; 
    cout << "2. Remove a completed request." << endl; 
    cout << "3. Process the next request." << endl; 
    cout << "4. Display active requests." << endl; 
    cout << "5. Find a particular request." << endl; 
    cout << "6. Simulate 10 scheduling cycles." << endl; 
    cout << "7. Exit." << endl; 
} 
 
int main() 
{ 
    Request_Scheduler scheduler; 
 
    int choice; 
    int requestID; 
    int userID; 
    int time; 
    string modelName; 
 
    do 
    { 
        menu(); 
 
        cout << "Enter your choice please: "; 
        cin >> choice; 
 
        cout << endl; 
 
        if(choice == 1) 
        { 
            cout << "Enter Request ID: "; 
            cin >> requestID; 
 
            cout << "Enter User ID: "; 
            cin >> userID; 
 
            cout << "Enter Model Name: "; 
            cin >> modelName; 
 
            cout << "Enter Processing Time in seconds: "; 
            cin >> time; 
 
            scheduler.AddRequest(requestID, userID, modelName, time); 
        } 
        else if(choice == 2) 
        { 
            cout << "Enter completed Request ID: "; 
            cin >> requestID; 
 
            scheduler.RemoveRequest(requestID); 
        } 
        else if(choice == 3) 
        { 
            scheduler.ProcessNextRequest(); 
        } 
        else if(choice == 4) 
        { 
            scheduler.DisplayRequests(); 
        } 
        else if(choice == 5) 
        { 
            cout << "Enter Request ID to find: "; 
            cin >> requestID; 
 
            scheduler.FindRequest(requestID); 
        } 
        else if(choice == 6) 
        { 
            scheduler.SimulateCycles(); 
        } 
        else if(choice == 7) 
        { 
            cout << "Exiting Request Scheduler." << endl; 
        } 
        else 
        { 
            cout << "Invalid choice. Try again." << endl; 
        } 
 
    } while(choice != 7); 
 
    return 0; 
}