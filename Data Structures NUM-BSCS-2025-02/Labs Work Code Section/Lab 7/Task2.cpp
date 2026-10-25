#include<iostream> 
using namespace std; 
 
bool isEmpty(int front) 
{ 
    if(front==-1) 
    { 
        return true; 
    } 
    return false; 
} 
 
bool isFull(int front,int rear,int size) 
{ 
    if((rear+1)%size==front) 
    { 
        return true; 
    } 
    return false; 
} 
 
void enqueue(int queue[],int &front,int &rear,int size) 
{ 
    if(isFull(front,rear,size)) 
    { 
        cout<<"Queue is full."<<endl; 
    } 
    else 
    { 
        if(front==-1) 
        { 
            front=0; 
        } 
 
        rear=(rear+1)%size; 
 
        cout<<"Enter value please: "; 
        cin>>queue[rear]; 
    } 
} 
 
void dequeue(int queue[],int &front,int &rear,int size) 
{ 
    if(isEmpty(front)) 
    { 
        cout<<"Queue is empty."<<endl; 
    } 
    else 
    { 
        cout<<"Removed value: "<<queue[front]<<endl; 
 
        if(front==rear) 
        { 
            front=-1; 
            rear=-1; 
        } 
        else 
        { 
            front=(front+1)%size; 
        } 
    } 
} 
 
void peek(int queue[],int front) 
{ 
    if(isEmpty(front)) 
    { 
        cout<<"Queue is empty."<<endl; 
    } 
    else 
    { 
        cout<<"Front value: "<<queue[front]<<endl; 
    } 
} 
 
int main() 
{ 
    int size; 
 
    cout<<"Enter queue size: "; 
    cin>>size; 
    int queue[size]; 
 
    if(size<=0) 
    { 
        cout<<"Invalid queue size."<<endl; 
        return 0; 
    } 
 
    int front=-1, rear=-1; 
    int choice; 
 
    do 
    { 
        cout<<endl<<"----- CIRCULAR QUEUE MENU -----"<<endl; 
        cout<<"1. Enqueue"<<endl; 
        cout<<"2. Dequeue"<<endl; 
        cout<<"3. Peek"<<endl; 
        cout<<"4. Check Empty"<<endl; 
        cout<<"5. Check Full"<<endl; 
        cout<<"6. Exit"<<endl; 
        cout<<"Enter your choice: "; 
        cin>>choice; 
 
        if(choice==1) 
        { 
            enqueue(queue,front,rear,size); 
        } 
        else if(choice==2) 
        { 
            dequeue(queue,front,rear,size); 
        } 
        else if(choice==3) 
        { 
            peek(queue,front); 
        } 
        else if(choice==4) 
        { 
            if(isEmpty(front)) 
            { 
                cout<<"Queue is empty."<<endl; 
            } 
            else 
            { 
                cout<<"Queue is not empty."<<endl; 
            } 
        } 
        else if(choice==5) 
        { 
            if(isFull(front,rear,size)) 
            { 
                cout<<"Queue is full."<<endl; 
            } 
            else 
            { 
                cout<<"Queue is not full."<<endl; 
            } 
        } 
        else if(choice==6) 
        { 
            cout<<"Program ended."<<endl; 
        } 
        else 
        { 
            cout<<"Invalid choice."<<endl; 
        } 
 
    }while(choice!=6); 
 
    return 0; 
} 