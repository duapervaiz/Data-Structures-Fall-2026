#include <iostream> 
#include <string> 
using namespace std; 
 
class Node 
{ 
public: 
    string data; 
    Node* next; 
 
    Node(string value) 
    { 
        data = value; 
        next = NULL; 
    } 
}; 
 
class Stack 
{ 
public: 
    Node* top; 
 
    Stack() 
    { 
        top = NULL; 
    } 
 
    void push(string value) 
    { 
        Node* temp = new Node(value); 
        temp->next = top; 
        top = temp; 
    } 
 
    string pop() 
    { 
        if (top == NULL) 
            return ""; 
 
        Node* temp = top; 
        string value = top->data; 
        top = top->next; 
        delete temp; 
 
        return value; 
    } 
 
    string peek() 
    { 
        if (top == NULL) 
            return ""; 
 
        return top->data; 
    } 
 
    bool isEmpty() 
    { 
        return top == NULL; 
    } 
}; 
 
bool isOperator(char ch) 
{ 
    return ch == '+' || ch == '-' || 
           ch == '*' || ch == '/' || 
           ch == '^' || ch == '$'; 
} 
 
string prefixToInfix(string prefix) 
{ 
    Stack s; 
 
    for (int i = (int)prefix.length() - 1; i >= 0; i--) 
    { 
        char ch = prefix[i]; 
 
        if (ch == ' ') 
            continue; 
 
        if (isOperator(ch)) 
        { 
            string first = s.pop(); 
            string second = s.pop(); 
 
            string result = "(" + first + ch + second + ")"; 
            s.push(result); 
        } 
        else 
        { 
            string operand = ""; 
            operand += ch; 
            s.push(operand); 
        } 
    } 
 
    return s.pop(); 
} 
 
string prefixToPostfix(string prefix) 
{ 
    Stack s; 
 
    for (int i = (int)prefix.length() - 1; i >= 0; i--) 
    { 
        char ch = prefix[i]; 
 
        if (ch == ' ') 
            continue; 
 
        if (isOperator(ch)) 
        { 
            string first = s.pop(); 
            string second = s.pop(); 
 
            string result = first + second + ch; 
            s.push(result); 
        } 
        else 
        { 
            string operand = ""; 
            operand += ch; 
            s.push(operand); 
        } 
    } 
 
    return s.pop(); 
} 
 
int main() 
{ 
    string prefix; 
    int choice; 
 
    cout << endl <<"Enter prefix expression: "; 
    getline(cin, prefix); 
 
    cout << "1. Infix" << endl; 
    cout << "2. Postfix" << endl <<endl; 
    cout << "Enter choice: "; 
    cin >> choice; 
 
    if (choice == 1) 
    { 
        cout << "Infix: " << prefixToInfix(prefix); 
        cout<<"Exiting...."<<endl; 
    }  
    else if (choice == 2) 
    { 
        cout << "Postfix: " << prefixToPostfix(prefix); 
        cout<<"Exiting...."<<endl; 
    } 
    else 
        cout << "Invalid choice"; 
 
    return 0; 
} 
