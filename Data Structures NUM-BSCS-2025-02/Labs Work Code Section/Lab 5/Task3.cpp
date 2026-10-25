#include<iostream> 
#include<string> 
using namespace std; 
 
class Node 
{ 
public: 
    int Lecture_ID; 
    string Lecture_Title; 
    int Duration; 
    Node* next; 
 
    Node(int ID, string title, int duration) 
    { 
        Lecture_ID = ID; 
        Lecture_Title = title; 
        Duration = duration; 
        next = NULL; 
    } 
}; 
 
class Playlist 
{ 
private: 
    Node* head; 
    Node* current; 
    bool repeat; 
 
public: 
    Playlist() 
    { 
        head = NULL; 
        current = NULL; 
        repeat = false; 
    } 
 
    void AddLecture(int ID, string title, int duration) 
    { 
        Node* newNode = new Node(ID, title, duration); 
 
        if(head == NULL) 
        { 
            head = newNode; 
            newNode->next = head; 
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
 
        if(current == NULL) 
        { 
            current = head; 
        } 
 
        cout << "Lecture added successfully." << endl; 
    } 
 
    void DeleteLecture(int ID) 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
        Node* previousNode = NULL; 
 
        do 
        { 
            if(temp->Lecture_ID == ID) 
            { 
                break; 
            } 
 
            previousNode = temp; 
            temp = temp->next; 
 
        } while(temp != head); 
 
        if(temp->Lecture_ID != ID) 
        { 
            cout << "Lecture ID not found." << endl; 
            return; 
        } 
 
        if(temp->next == head && temp == head) 
        { 
            delete temp; 
            head = NULL; 
            current = NULL; 
 
            cout << "Lecture deleted successfully." << endl; 
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
 
        cout << "Lecture deleted successfully." << endl; 
    } 
 
    void StartPlaylist() 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty. Add lectures first." << endl; 
            return; 
        } 
 
        current = head; 
 
        cout << "Playlist started." << endl; 
        cout << "Now Playing: " << current->Lecture_Title << endl; 
        cout << "Duration: " << current->Duration << " minutes" << endl; 
    } 
 
    void PlayNextLecture() 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        if(current == NULL) 
        { 
            current = head; 
        } 
        else 
        { 
            current = current->next; 
        } 
 
        cout << "Now Playing: " << current->Lecture_Title << endl; 
        cout << "Lecture ID: " << current->Lecture_ID << endl; 
        cout << "Duration: " << current->Duration << " minutes" << endl; 
 
        if(current == head && repeat == false) 
        { 
            cout << "You have reached the end of the playlist." << endl; 
        } 
        else if(current == head && repeat == true) 
        { 
            cout << "Playlist repeated. Starting again from the first lecture." << endl; 
        } 
    } 
 
    void DisplayLectures() 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        cout << endl << "===== ALL LECTURES =====" << endl; 
 
        do 
        { 
            cout << "Lecture ID: " << temp->Lecture_ID << endl; 
            cout << "Lecture Title: " << temp->Lecture_Title << endl; 
            cout << "Duration: " << temp->Duration << " minutes" << endl; 
 
            if(temp == current) 
            { 
                cout << "Status: Current Lecture" << endl; 
            } 
 
            cout << "------------------------" << endl; 
 
            temp = temp->next; 
 
        } while(temp != head); 
    } 
 
    void SearchLecture(int ID) 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        Node* temp = head; 
 
        do 
        { 
            if(temp->Lecture_ID == ID) 
            { 
                cout << "Lecture found!" << endl; 
                cout << "Lecture ID: " << temp->Lecture_ID << endl; 
                cout << "Lecture Title: " << temp->Lecture_Title << endl; 
                cout << "Duration: " << temp->Duration << " minutes" << endl; 
                return; 
            } 
 
            temp = temp->next; 
 
        } while(temp != head); 
 
        cout << "Lecture ID not found." << endl; 
    } 
 
    void CountLectures() 
    { 
        if(head == NULL) 
        { 
            cout << "Total lectures: 0" << endl; 
            return; 
        } 
 
        int count = 0; 
        Node* temp = head; 
 
        do 
        { 
            count++; 
            temp = temp->next; 
 
        } while(temp != head); 
 
        cout << "Total lectures: " << count << endl; 
    } 
 
    void SkipCurrentLecture() 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        if(current == NULL) 
        { 
            current = head; 
        } 
        else 
        { 
            current = current->next; 
        } 
 
        cout << "Current lecture skipped." << endl; 
        cout << "Now Playing: " << current->Lecture_Title << endl; 
    } 
 
    void RepeatPlaylist() 
    { 
        if(head == NULL) 
        { 
            cout << "Playlist is empty. Add lectures first." << endl; 
            return; 
        } 
 
        if(repeat == false) 
        { 
            repeat = true; 
            cout << "Repeat mode enabled." << endl; 
        } 
        else 
        { 
            repeat = false; 
            cout << "Repeat mode disabled." << endl; 
        } 
    } 
}; 
 
void menu() 
{ 
    cout << endl; 
    cout << "===== SMART LEARNING PLAYLIST =====" << endl; 
    cout << "1. Add a lecture." << endl; 
    cout << "2. Delete a lecture." << endl; 
    cout << "3. Start the playlist." << endl; 
    cout << "4. Play the next lecture." << endl; 
    cout << "5. Display all lectures." << endl; 
    cout << "6. Search for a lecture." << endl; 
    cout << "7. Count lectures." << endl; 
    cout << "8. Skip the current lecture." << endl; 
    cout << "9. Repeat the playlist automatically." << endl; 
    cout << "10. Exit." << endl; 
} 
 
int main() 
{ 
    Playlist list; 
 
    int choice; 
    int ID; 
    int duration; 
    string title; 
 
    do 
    { 
        menu(); 
 
        cout << "Enter your choice please: "; 
        cin >> choice; 
 
        cout << endl; 
 
        if(choice == 1) 
        { 
            cout << "Enter Lecture ID: "; 
            cin >> ID; 
 
            cout << "Enter Lecture Title: "; 
            cin>>title; 
 
            cout << "Enter Duration in minutes: "; 
            cin >> duration; 
 
            list.AddLecture(ID, title, duration); 
        } 
        else if(choice == 2) 
        { 
            cout << "Enter Lecture ID to delete: "; 
            cin >> ID; 
 
            list.DeleteLecture(ID); 
        } 
        else if(choice == 3) 
        { 
            list.StartPlaylist(); 
        } 
        else if(choice == 4) 
        { 
            list.PlayNextLecture(); 
        } 
        else if(choice == 5) 
        { 
            list.DisplayLectures(); 
        } 
        else if(choice == 6) 
        { 
            cout << "Enter Lecture ID to search: "; 
            cin >> ID; 
 
            list.SearchLecture(ID); 
        } 
        else if(choice == 7) 
        { 
            list.CountLectures(); 
        } 
        else if(choice == 8) 
        { 
            list.SkipCurrentLecture(); 
        } 
        else if(choice == 9) 
        { 
            list.RepeatPlaylist(); 
        } 
        else if(choice == 10) 
        { 
            cout << "Exiting Smart Learning Playlist." << endl; 
        } 
        else 
        { 
            cout << "Invalid choice. Try again." << endl; 
        } 
 
    } while(choice != 10); 
 
    return 0; 
} 
