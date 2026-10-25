 
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
 
string postfixToInfix(string postfix) 
{ 
    Stack s; 
 
    for (int i = 0; i < (int)postfix.length(); i++) 
    { 
        char ch = postfix[i]; 
 
        if (ch == ' ') 
            continue; 
 
        if (isOperator(ch)) 
        { 
            string second = s.pop(); 
            string first = s.pop(); 
 
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
 
string postfixToPrefix(string postfix) 
{ 
    Stack s; 
 
    for (int i = 0; i < (int)postfix.length(); i++) 
    { 
        char ch = postfix[i]; 
 
        if (ch == ' ') 
            continue; 
 
        if (isOperator(ch)) 
        { 
            string second = s.pop(); 
            string first = s.pop(); 
 
            string result = ch + first + second; 
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
    string postfix; 
    int choice; 
 
    cout << endl<<"Enter postfix expression: "; 
    getline(cin, postfix); 
 
    cout << "1. Infix" << endl; 
    cout << "2. Prefix" << endl; 
    cout << endl<<"Enter choice: "; 
    cin >> choice; 
 
    if (choice == 1) 
    { 
        cout << "Infix: " << postfixToInfix(postfix)<<endl; 
        cout<<"Exiting...."<<endl; 
    }   
    else if (choice == 2) 
    { 
        cout << "Prefix: " << postfixToPrefix(postfix)<<endl; 
        cout<<"Exiting...."<<endl; 
    }     
    else 
        cout << "Invalid choice"; 
 
    return 0; 
} 