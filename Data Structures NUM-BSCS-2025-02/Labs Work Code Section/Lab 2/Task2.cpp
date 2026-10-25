#include <iostream> 
using namespace std; 
 
int number; 
bool check; 
 
void insert(int *&array, int &size) 
{ 
    int *newArray = new int[size + 1]; 
 
    for(int i = 0; i < size; i++) 
    { 
        newArray[i] = array[i]; 
    } 
 
    cout << "Enter the element you want to enter: "; 
    cin >> newArray[size]; 
 
    delete[] array; 
 
    array = newArray; 
    size++; 
} 
 
void update(int *array, int size) 
{ 
    cout << "Enter the index number you want to update: "; 
    cin >> number; 
 
    if(number >= 0 && number < size) 
    { 
        cout << "Enter the value that you want to update instead of " 
             << array[number] << ": "; 
        cin >> array[number]; 
    } 
    else 
    { 
        cout << "Invalid index." << endl; 
    } 
} 
 
void search(int *array, int size, bool &checking, int &index) 
{ 
    cout << "Enter the number you want to search: "; 
    cin >> number; 
 
    checking = false; 
 
    for(int i = 0; i < size; i++) 
    { 
        if(number == array[i]) 
        { 
            checking = true; 
            index = i; 
            return; 
        } 
    } 
} 
 
void removeElement(int *&array, int &size) 
{ 
    cout << "Enter the number you want to delete: "; 
    cin >> number; 
 
    int index = -1; 
 
    for(int i = 0; i < size; i++) 
    { 
        if(array[i] == number) 
        { 
            index = i; 
            break; 
        } 
    } 
 
    if(index == -1) 
    { 
        cout << "The number is not found." << endl; 
        return; 
    } 
 
    int *newArray = new int[size - 1]; 
 
    for(int i = 0; i < index; i++) 
    { 
        newArray[i] = array[i]; 
    } 
 
    for(int i = index; i < size - 1; i++) 
    { 
        newArray[i] = array[i + 1]; 
    } 
 
    delete[] array; 
 
    array = newArray; 
    size--; 
 
    cout << "The number has been deleted." << endl; 
} 
 
void menu() 
{ 
    cout <<endl << "**** Dynamic Array Operations ****" << endl; 
    cout << "1. Insert a new element." << endl; 
    cout << "2. Update the array." << endl; 
    cout << "3. Search an element in the array." << endl; 
    cout << "4. Delete an element from the array." << endl; 
    cout << "5. Exit." << endl << endl; 
} 
 
int main() 
{ 
    int size = 0; 
    int choice; 
    bool checking; 
    int index; 
 
    int *dynamic_array = new int[0]; 
 
    do 
    { 
        menu(); 
 
        cout << "Enter your choice please: "; 
        cin >> choice; 
 
        if(choice == 1) 
        { 
            insert(dynamic_array, size); 
        } 
        else if(choice == 2) 
        { 
            if(size == 0) 
            { 
                cout << "Array is empty." << endl; 
            } 
            else 
            { 
                update(dynamic_array, size); 
            } 
        } 
        else if(choice == 3) 
        { 
            if(size == 0) 
            { 
                cout << "Array is empty." << endl; 
            } 
            else 
            { 
                search(dynamic_array, size, checking, index); 
 
                if(checking == true) 
                { 
                    cout << "The number " << number 
                         << " is found on index " << index << "." << endl; 
                } 
                else 
                { 
                    cout << "The number " << number 
                         << " is not found." << endl; 
                } 
            } 
        } 
        else if(choice == 4) 
        { 
            if(size == 0) 
            { 
                cout << "Array is empty." << endl; 
            } 
            else 
            { 
                removeElement(dynamic_array, size); 
            } 
        } 
        else if(choice == 5) 
        { 
            cout << "Terminating Program...." << endl; 
        } 
        else 
        { 
            cout << "Invalid Entry. Try Again." << endl; 
        } 
 
    } while(choice != 5); 
 
    delete[] dynamic_array; 
 
    return 0; 
} 