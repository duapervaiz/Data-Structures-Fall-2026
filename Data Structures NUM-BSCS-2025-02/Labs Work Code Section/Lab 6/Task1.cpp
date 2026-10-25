#include <iostream> 
#include <string> 
using namespace std; 
 
class Node 
{ 
public: 
    char data; 
    Node* next; 
 
    Node(char value) 
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
 
    void push(char value) 
    { 
        Node* temp = new Node(value); 
        temp->next = top; 
        top = temp; 
    } 
 
    char pop() 
    { 
        if (top == NULL) 
            return 0; 
 
        Node* temp = top; 
        char value = top->data; 
        top = top->next; 
        delete temp; 
 
        return value; 
    } 
 
    char peek() 
    { 
        if (top == NULL) 
            return 0; 
 
        return top->data; 
    } 
 
    bool isEmpty() 
    { 
        return top == NULL; 
    } 
}; 
 
int priority(char op) 
{ 
    if (op == '^' || op == '$') 
        return 3; 
    else if (op == '*' || op == '/') 
        return 2; 
    else if (op == '+' || op == '-') 
        return 1; 
 
    return 0; 
} 
 
bool isOperator(char ch) 
{ 
    return ch == '+' || ch == '-' || 
           ch == '*' || ch == '/' || 
           ch == '^' || ch == '$'; 
} 
 
string reverseString(string str) 
{ 
    string result = ""; 
 
    for (int i = (int)str.length() - 1; i >= 0; i--) 
    { 
        if (str[i] == '(') 
            result += ')'; 
        else if (str[i] == ')') 
            result += '('; 
        else 
            result += str[i]; 
    } 
 
    return result; 
} 
 
string infixToPostfix(string infix, bool reversed = false) 
{ 
    Stack s; 
    string result = ""; 
 
    for (int i = 0; i < (int)infix.length(); i++) 
    { 
        char ch = infix[i]; 
 
        if (ch == ' ') 
            continue; 
 
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) 
        { 
            result += ch; 
        } 
        else if (ch == '(') 
        { 
            s.push(ch); 
        } 
        else if (ch == ')') 
        { 
            while (!s.isEmpty() && s.peek() != '(') 
                result += s.pop(); 
 
            if (!s.isEmpty()) 
                s.pop(); 
        } 
        else if (isOperator(ch)) 
        { 
            while (!s.isEmpty() && s.peek() != '(') 
            { 
                if (priority(s.peek()) > priority(ch)) 
                    result += s.pop(); 
                else if (priority(s.peek()) == priority(ch)) 
                { 
                    if (reversed && (ch == '^' || ch == '$')) 
                        result += s.pop(); 
                    else if (!reversed && ch != '^' && ch != '$') 
                        result += s.pop(); 
                    else 
                        break; 
                } 
                else 
                    break; 
            } 
 
            s.push(ch); 
        } 
    } 
 
    while (!s.isEmpty()) 
        result += s.pop(); 
 
    return result; 
} 
 
string infixToPrefix(string infix) 
{ 
    string reversed = reverseString(infix); 
    string result = infixToPostfix(reversed, true); 
 
    return reverseString(result); 
} 
 
int main() 
{ 
    string infix; 
    int choice; 
 
    cout << endl << "Enter infix expression: "; 
    getline(cin, infix); 
 
    cout << endl << "1. Postfix" << endl; 
    cout << "2. Prefix" << endl; 
    cout << endl << "Enter choice: "; 
    cin >> choice; 
 
    if (choice == 1) 
    { 
        cout << "Postfix: " << infixToPostfix(infix) << endl; 
        cout<<"Exiting...."<<endl; 
    } 
    else if (choice == 2) 
    { 
        cout << "Prefix: " << infixToPrefix(infix) <<endl ; 
        cout<<"Exiting...."<<endl; 
    }   
    else 
        cout << "Invalid choice"; 
 
    return 0; 
}