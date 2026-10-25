#include<iostream> 
#include<string> 
 
using namespace std; 
 
struct Node 
{ 
    char data; 
    Node* next; 
}; 
 
int main() 
{ 
    string exp; 
    Node* top=NULL; 
 
    cout<<"Enter an expression: "; 
    cin>>exp; 
 
    for(int i=0;i<exp.length();i++) 
    { 
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[') 
        { 
            Node* temp=new Node; 
            temp->data=exp[i]; 
            temp->next=top; 
            top=temp; 
        } 
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']') 
        { 
            if(top==NULL) 
            { 
                cout<<"Not Balanced"; 
                return 0; 
            } 
 
            if((exp[i]==')'&&top->data=='(')|| 
               (exp[i]=='}'&&top->data=='{')|| 
               (exp[i]==']'&&top->data=='[')) 
            { 
                Node* temp=top; 
                top=top->next; 
                delete temp; 
            } 
            else 
            { 
                cout<<"Not Balanced"; 
                return 0; 
            } 
        } 
    } 
 
    if(top==NULL) 
        cout<<"Balanced"; 
    else 
        cout<<"Not Balanced"; 
 
    return 0;
}