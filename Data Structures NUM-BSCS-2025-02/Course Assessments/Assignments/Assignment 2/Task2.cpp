#include <iostream> 
using namespace std; 
 
struct Node 
{ 
    int disk_position; 
    Node* next; 
}; 
 
void push(Node*& top,int disk) 
{ 
    Node* temp=new Node; 
    temp->disk_position=disk; 
    temp->next=top; 
    top=temp; 
} 
 
int pop(Node*& top) 
{ 
    int disk=top->disk_position; 
    Node* temp=top; 
    top=top->next; 
    delete temp; 
    return disk; 
} 
 
void display(Node* top,char name) 
{ 
    cout<<"Rod "<<name<<": "; 
 
    Node* temp=top; 
 
    while(temp!=NULL) 
    { 
        cout<<temp->disk_position<<" "; 
        temp=temp->next; 
    } 
    cout<<endl; 
} 
 
int main() 
{ 
    Node* A=NULL; 
    Node* B=NULL; 
    Node* C=NULL; 
 
    int n,moves=0; 
    int minimum=1; 
    char from,to; 
 
    cout<<endl<<"Enter number of disks: "; 
    cin>>n; 
 
    if(n<1) 
    { 
        cout<<endl<<"Invalid number of disks"; 
        return 0; 
    } 
 
    for(int i=n;i>=1;i--) 
    { 
        push(A,i); 
    } 
 
    for(int i=1;i<=n;i++) 
    { 
        minimum=minimum*2; 
    } 
 
    minimum=minimum-1; 
 
    cout<<"Minimum moves required: "<<minimum<<endl; 
 
    while(true) 
    { 
        cout<<endl; 
        display(A,'A'); 
        display(B,'B'); 
        display(C,'C'); 
        cout<<endl; 
 
        if(C!=NULL && C->disk_position==1 && n==1) 
            break; 
 
        cout<<"Move disk from rod (A/B/C): "; 
        cin>>from; 
 
        cout<<"Move disk to rod (A/B/C): "; 
        cin>>to; 
 
        cout<<endl; 
 
        Node* source=NULL; 
        Node* destination=NULL; 
 
        if(from=='A'||from=='a') 
            source=A; 
        else if(from=='B'||from=='b') 
            source=B; 
        else if(from=='C'||from=='c') 
            source=C; 
        else 
        { 
            cout<<"Invalid source rod!"<<endl; 
            continue; 
        } 
 
        if(to=='A'||to=='a') 
            destination=A; 
        else if(to=='B'||to=='b') 
            destination=B; 
        else if(to=='C'||to=='c') 
            destination=C; 
        else 
        { 
            cout<<"Invalid destination rod!"<<endl<<endl; 
            continue; 
        } 
 
        if(from==to) 
        { 
            cout<<"Both rods cannot be the same!"<<endl<<endl; 
            continue; 
        } 
 
        if(source==NULL) 
        { 
            cout<<"Source rod is empty!"<<endl<<endl; 
            continue; 
        } 
 
        if(destination!=NULL && 
           source->disk_position>destination->disk_position) 
        { 
            cout<<"Illegal move!"<<endl<<endl; 
            continue; 
        } 
 
        int disk=pop(source); 
 
        if(from=='A'||from=='a') 
            A=source; 
        else if(from=='B'||from=='b') 
            B=source; 
        else 
            C=source; 
 
        if(to=='A'||to=='a') 
            push(A,disk); 
        else if(to=='B'||to=='b') 
            push(B,disk); 
        else 
            push(C,disk); 
 
        moves++; 
 
        cout<<"Move successful! Total moves: "<<moves<<endl<<endl; 
 
        if(C!=NULL && C->disk_position==1) 
        { 
            Node* temp=C; 
            int count=0; 
 
            while(temp!=NULL) 
            { 
                count++; 
                temp=temp->next; 
            } 
 
            if(count==n) 
                break; 
        } 
    } 
 
    display(A,'A'); 
    display(B,'B'); 
    display(C,'C'); 
 
    cout<<"Congratulations! You won!"<<endl; 
    cout<<"Total moves: "<<moves<<endl; 
    cout<<"Minimum moves: "<<minimum<<endl; 
 
    return 0; 
} 