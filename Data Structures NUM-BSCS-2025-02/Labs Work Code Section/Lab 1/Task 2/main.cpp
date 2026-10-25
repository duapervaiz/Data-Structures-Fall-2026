#include<iostream> 
using namespace std; 
 
class Numbers 
{ 
private: 
    int *ptr; 
    int size; 
 
public: 
    Numbers(int s)  
    { 
        size = s; 
        ptr = new int[size]; 
    } 
 
    void assignValues(int arr[]) 
    { 
        for(int i = 0; i < size; i++) 
        { 
            ptr[i] = arr[i]; 
        } 
    } 
 
    Numbers(const Numbers &obj)  
    { 
        size = obj.size; 
        ptr = new int[size]; 
        for(int i = 0; i < size; i++) 
        { 
            ptr[i] = obj.ptr[i]; 
        } 
    } 
 
    Numbers& operator=(const Numbers& obj) 
    { 
        if (this == &obj)  
        { 
            return *this; 
        } 
 
        size = obj.size; 
        delete[] ptr; 
        ptr = new int[size]; 
        for(int i = 0; i < size; i++) 
        { 
            ptr[i] = obj.ptr[i]; 
        } 
 
        return *this; 
    } 
 
    void display() 
    { 
        for(int i = 0; i < size; i++) 
        { 
            cout << ptr[i] << " "; 
        } 
        cout << endl; 
    } 
 
    ~Numbers()  
    { 
        delete[] ptr; 
    } 
}; 
 
int main() 
{ 
    int arr[4] = {11, 22, 33, 44}; 
    Numbers Num1(4); 
    Num1.assignValues(arr); 
     
    Numbers Num2(Num1);  
     
    Numbers Num3(4); 
    Num3 = Num1;         
 
    cout << "Num 1: "; 
    Num1.display(); 
 
    cout << "Num 2: "; 
    Num2.display(); 
 
    cout << "Num 3: "; 
    Num3.display(); 
 
    return 0; 
}