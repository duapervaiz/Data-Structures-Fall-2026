#include <iostream> 
using namespace std; 
 
bool commonFriend(bool friends[5][5], int person1, int person2) 
{ 
    for(int i = 0; i < 5; i++) 
    { 
        if(friends[person1][i] == true && 
           friends[person2][i] == true) 
        { 
            return true; 
        } 
    } 
 
    return false; 
} 
 
int main() 
{ 
    bool friends[5][5] = 
    { 
        {false, true,  false, true,  true}, 
        {true,  false, true,  false, true}, 
        {false, true,  false, false, false}, 
        {true,  false, false, false, true}, 
        {true,  true,  false, true,  false} 
    }; 
 
    int person1, person2; 
 
    cout << "Enter first person: "; 
    cin >> person1; 
 
    cout << "Enter second person: "; 
    cin >> person2; 
 
    if(commonFriend(friends, person1, person2)) 
    { 
        cout << "They have a common friend." << endl; 
    } 
    else 
    { 
        cout << "They do not have a common friend." << endl; 
    } 
 
    return 0; 
}