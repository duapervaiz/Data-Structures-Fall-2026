#include<iostream> 
using namespace std; 
 
bool isEmpty(int front,int rear) 
{ 
    if(front==rear) 
    { 
        return true; 
    } 
    return false; 
} 
 
bool isFull(int rear,int size) 
{ 
    if(rear>=size-1) 
    { 
        return true; 
    } 
    return false; 
} 
 
void enque(int queue[],int &rear,int size) 
{ 
    if(isFull(rear,size)) 
    { 
        cout<<"Queue is full."<<endl; 
    } 
    else 
    { 
        rear++; 
        cout<<"Enter value please: "; 
        cin>>queue[rear]; 
    } 
} 
 
void deque(int queue[],int &front,int rear) 
{ 
    if(isEmpty(front,rear)) 
    { 
        cout<<"Queue is empty."<<endl; 
    } 
    else 
    { 
        front++; 
        cout<<"Removed value: "<<queue[front]<<endl; 
    } 
} 
 
void peek(int queue[],int front,int rear) 
{ 
    if(isEmpty(front,rear)) 
    { 
        cout<<"Queue is empty."<<endl; 
    } 
    else 
    { 
        cout<<"Front value: "<<queue[front+1]<<endl; 
    } 
} 
 
int main() 
{ 
    int size; 
 
    cout<<"Enter queue size : "; 
    cin>>size; 
    int queue[size]; 
 
    if(size<=0) 
    { 
        cout<<"Invalid queue size."<<endl; 
        return 0; 
    } 
 
    int rear=-1, front=-1; 
    int choice; 
 
    do 
    { 
        cout<<endl<<"----- QUEUE MENU -----"<<endl; 
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
            enque(queue,rear,size); 
        } 
        else if(choice==2) 
        { 
            deque(queue,front,rear); 
        } 
        else if(choice==3) 
        { 
            peek(queue,front,rear); 
        } 
        else if(choice==4) 
        { 
            if(isEmpty(front,rear)) 
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
            if(isFull(rear,size)) 
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