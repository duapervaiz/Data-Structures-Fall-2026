#include <iostream> 
#include <string> 
using namespace std; 
// Node structure representing a song in the doubly linked list 
class Song 
{ 
public: 
int id; 
string title; 
string artist; 
int duration; 
Song *previous; 
Song *next; 
Song(int songID, string songTitle, string songArtist, int songDuration) 
{ 
id = songID; 
title = songTitle; 
artist = songArtist; 
duration = songDuration; 
previous = NULL; 
        next = NULL; 
    } 
}; 
 
class Playlist 
{ 
private: 
    Song *head; 
    Song *playing; 
    bool repeat; 
    int nextID; 
 
public: 
    Playlist() 
    { 
        head = NULL; 
        playing = NULL; 
        repeat = false; 
        nextID = 1; 
    } 
 
    void showCurrent() 
    { 
        if (playing == NULL) 
            cout << "No song is playing." << endl; 
        else 
            cout << "Currently playing: " << playing->title << " - " << playing->artist << endl; 
    } 
 
    // Requirement 1: Add a song to the end of doubly linked list 
    void addSong(string title, string artist, int duration) 
    { 
        Song *newSong = new Song(nextID, title, artist, duration); 
        nextID++; 
 
        // Case 1: Empty list (New song becomes head and currently playing song) 
        if (head == NULL) 
        { 
            head = newSong; 
            playing = newSong; 
        } 
        // Case 2: Append to the end of the doubly linked list 
        else 
        { 
            Song *temp = head; 
 
            // Traverse to the last node 
            while (temp->next != NULL) 
                temp = temp->next; 
 
            // Link previous last node to new node and new node back to last node 
            temp->next = newSong; 
            newSong->previous = temp; 
        } 
 
        cout << "Song added. ID: " << newSong->id << endl; 
    } 
 
    // Requirement 2: Remove a song by ID with complete edge-case handling 
    void removeSong(int id) 
    { 
        Song *temp = head; 
 
        // Traverse to find node with matching ID 
        while (temp != NULL && temp->id != id) 
            temp = temp->next; 
 
        if (temp == NULL) 
        { 
            cout << "Song not found." << endl; 
            return; 
        } 
 
        // Pointer Update 1: Unlink from previous node if not head 
        if (temp->previous != NULL) 
            temp->previous->next = temp->next; 
        else 
            head = temp->next; // Update head pointer if deleting first node 
 
        // Pointer Update 2: Unlink from next node if not tail 
        if (temp->next != NULL) 
            temp->next->previous = temp->previous; 
 
        // Pointer Update 3: Safely update currently playing pointer 
        if (playing == temp) 
        { 
            if (temp->next != NULL) 
                playing = temp->next; 
            else if (temp->previous != NULL) 
                playing = temp->previous; 
            else 
                playing = NULL; // List becomes completely empty 
        } 
 
        delete temp; 
        cout << "Song removed." << endl; 
    } 
 
    // Requirement 3: Play next song (supports repeat mode) 
    void playNext() 
    { 
        if (playing == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        if (playing->next != NULL) 
            playing = playing->next; 
        else if (repeat) 
            playing = head; // Wrap around to first song in repeat mode 
        else 
        { 
            cout << "This is the last song." << endl; 
            return; 
        } 
 
        showCurrent(); 
    } 
 
    // Requirement 4: Play previous song (supports repeat mode) 
    void playPrevious() 
    { 
        if (playing == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        if (playing->previous != NULL) 
            playing = playing->previous; 
        else if (repeat) 
        { 
            // Wrap around to the last song in repeat mode 
            Song *temp = head; 
            while (temp->next != NULL) 
                temp = temp->next; 
 
            playing = temp; 
        } 
        else 
        { 
            cout << "This is the first song." << endl; 
            return; 
        } 
 
        showCurrent(); 
    } 
 
    // Requirement 5: Search for a song by title 
    void searchSong(string title) 
    { 
        Song *temp = head; 
 
        while (temp != NULL) 
        { 
            if (temp->title == title) 
            { 
                cout << "Song found: " << temp->title 
                     << " by " << temp->artist << endl; 
                cout << "Song ID: " << temp->id << endl; 
                return; 
            } 
            temp = temp->next; 
        } 
 
        cout << "Song not found." << endl; 
    } 
 
    // Requirement 6: Display entire playlist 
    void display() 
    { 
        if (head == NULL) 
        { 
            cout << "Playlist is empty." << endl; 
            return; 
        } 
 
        Song *temp = head; 
        cout << endl << "Playlist:" << endl; 
 
        while (temp != NULL) 
        { 
            cout << "ID: " << temp->id << " | " << temp->title << " - "<< temp->artist << " (" << temp->duration << " sec)" 
<< endl; 
            temp = temp->next; 
        } 
    } 
 
    // Requirement 7: Shuffle playlist by swapping node contents 
    void shuffle() 
    { 
        if (head == NULL || head->next == NULL) 
        { 
            cout << "Not enough songs to shuffle." << endl; 
            return; 
        } 
 
        Song *first = head; 
 
        // Swaps data between adjacent pairs to rearrange list without breaking pointers 
        while (first != NULL && first->next != NULL) 
        { 
            Song *second = first->next; 
 
            int tempID = first->id; 
            first->id = second->id; 
            second->id = tempID; 
 
            string tempTitle = first->title; 
            first->title = second->title; 
            second->title = tempTitle; 
 
            string tempArtist = first->artist; 
            first->artist = second->artist; 
            second->artist = tempArtist; 
 
            int tempDuration = first->duration; 
            first->duration = second->duration; 
            second->duration = tempDuration; 
 
            first = second->next; 
        } 
 
        playing = head; 
        cout << "Playlist order changed." << endl; 
        showCurrent(); 
    } 
 
    // Requirement 8: Enable/disable repeat mode 
    void setRepeat(bool setting) 
    { 
        repeat = setting; 
 
        if (repeat) 
            cout << "Repeat mode enabled." << endl; 
        else 
            cout << "Repeat mode disabled." << endl; 
    } 
 
    ~Playlist() 
    { 
        Song *temp = head; 
 
        while (temp != NULL) 
        { 
            Song *nextSong = temp->next; 
            delete temp; 
            temp = nextSong; 
        } 
    } 
}; 
 
int main() 
{ 
    Playlist myPlaylist; 
    int choice, id, duration, repeatChoice; 
    string title, artist; 
 
    do 
    { 
        cout << endl << "===== MUSIC PLAYLIST MENU =====" << endl; 
        cout << "1. Add song" << endl; 
        cout << "2. Remove song" << endl; 
        cout << "3. Play next song" << endl; 
        cout << "4. Play previous song" << endl; 
        cout << "5. Search song" << endl; 
        cout << "6. Display playlist" << endl; 
        cout << "7. Shuffle playlist" << endl; 
        cout << "8. Set repeat mode" << endl; 
        cout << "9. Show current song" << endl; 
        cout << "10. Exit" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        if (choice == 1) 
        { 
            cout << "Enter song title (use underscores for spaces): "; 
            cin >> title; 
 
            cout << "Enter artist name (use underscores for spaces): "; 
            cin >> artist; 
 
            cout << "Enter duration in seconds: "; 
            cin >> duration; 
 
            if (duration <= 0) 
                cout << "Duration must be greater than zero." << endl; 
            else 
                myPlaylist.addSong(title, artist, duration); 
        } 
        else if (choice == 2) 
        { 
            cout << "Enter song ID to remove: "; 
            cin >> id; 
            myPlaylist.removeSong(id); 
        } 
        else if (choice == 3) 
            myPlaylist.playNext(); 
        else if (choice == 4) 
            myPlaylist.playPrevious(); 
        else if (choice == 5) 
        { 
            cout << "Enter song title: "; 
            cin >> title; 
            myPlaylist.searchSong(title); 
        } 
        else if (choice == 6) 
            myPlaylist.display(); 
        else if (choice == 7) 
            myPlaylist.shuffle(); 
        else if (choice == 8) 
        { 
            cout << "Enter 1 to enable repeat or 0 to disable: "; 
            cin >> repeatChoice; 
 
            if (repeatChoice == 1) 
                myPlaylist.setRepeat(true); 
            else if (repeatChoice == 0) 
                myPlaylist.setRepeat(false); 
            else 
                cout << "Invalid repeat choice." << endl; 
        } 
        else if (choice == 9) 
            myPlaylist.showCurrent(); 
        else if (choice == 10) 
            cout << "Program ended." << endl; 
        else 
            cout << "Invalid choice." << endl; 
 
    } while (choice != 10); 
 
    return 0; 
} 