#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int students = 5; 
 
    int *subjects[5]; 
    int persons[5]; 
 
    size[0] = 5;   // Ali 
    size[1] = 4;   // Hiba 
    size[2] = 3;   // Asma 
    size[3] = 3;   // Zain 
    size[4] = 5;   // Faisal 
 
    for(int i = 0; i < students; i++) 
    { 
        subjects[i] = new int[size[i]]; 
    } 
 
    double data[5] = {3.66, 3.33, 4.0, 3.0, 2.66}; 
    double hiba[4] = {3.33, 3.0, 3.66, 3.0}; 
    double asma[3] = {4.0, 3.66, 2.66}; 
    double zain[3] = {2.66, 2.33, 4.0}; 
    double faisal[5] = {3.33, 3.66, 4.0, 3.0, 3.33}; 
 
    double sum; 
 
    sum = 0; 
    for(int i = 0; i < 5; i++) 
        sum = sum + data[i]; 
 
    cout << "Ali GPA = " << sum / 5 << endl; 
 
    sum = 0; 
    for(int i = 0; i < 4; i++) 
        sum = sum + hiba[i]; 
 
    cout << "Hiba GPA = " << sum / 4 << endl; 
 
    sum = 0; 
    for(int i = 0; i < 3; i++) 
        sum = sum + asma[i]; 
 
    cout << "Asma GPA = " << sum / 3 << endl; 
 
    sum = 0; 
    for(int i = 0; i < 3; i++) 
        sum = sum + zain[i]; 
 
    cout << "Zain GPA = " << sum / 3 << endl; 
 
    sum = 0; 
    for(int i = 0; i < 5; i++) 
        sum = sum + faisal[i]; 
 
    cout << "Faisal GPA = " << sum / 5 << endl; 
 
    for(int i = 0; i < students; i++) 
    { 
        delete[] subjects[i]; 
    } 
 
    return 0; 
} 