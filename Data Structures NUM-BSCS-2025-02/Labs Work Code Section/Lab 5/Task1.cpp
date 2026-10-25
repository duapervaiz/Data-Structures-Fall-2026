  #include<iostream> 
    #include<string> 
    using namespace std; 
 
    class Node 
    { 
    public: 
        int Task_ID; 
        string Description; 
        string status; 
        Node* next_task; 
 
        Node(int ID,string description,string Status) 
        { 
            Task_ID=ID; 
            Description=description; 
            status=Status; 
            next_task=NULL; 
        } 
    }; 
 
    class Task_Manager 
    { 
    private: 
        Node* head; 
 
    public: 
        Task_Manager() 
        { 
            head=NULL; 
        }     
 
        void InsertAtBeginning(int ID,string description,string Status) 
        { 
            Node* newNode = new Node(ID,description,Status); 
 
            if (head==NULL) 
            { 
                head=newNode; 
            } 
            else 
            { 
                newNode->next_task=head; 
                head=newNode; 
            } 
        } 
 
        void InsertAtEnd(int ID,string description,string Status) 
        { 
            Node* newNode=new Node(ID,description,Status); 
 
            if(head==NULL) 
            { 
                head=newNode; 
            } 
            else 
            { 
                Node* temp=head; 
 
                while(temp->next_task!=NULL) 
                { 
                    temp=temp->next_task; 
                } 
                temp->next_task=newNode; 
            } 
        } 
 
        void InsertAfterTaskID(int old_ID,int ID,string description,string Status) 
        { 
            if (head==NULL) 
            { 
                cout<<"List is empty.No Task exists."<<endl; 
            } 
            else 
            { 
                Node* temp=head; 
                while(temp!=NULL) 
                { 
                    if (temp->Task_ID==old_ID) 
                    { 
                        Node* newNode=new Node(ID,description,Status); 
 
                        newNode->next_task=temp->next_task; 
                        temp->next_task=newNode; 
                        return; 
                    } 
 
                    temp=temp->next_task; 
                } 
                cout << "Given node not found." << endl; 
            } 
        } 
 
        void DeleteUsingTaskID(int ID) 
        { 
            if (head==NULL) 
            { 
                cout<<"List is empty. No task exists."<<endl; 
                return; 
            } 
 
            if(head->Task_ID==ID) 
            { 
                Node* temp=head; 
                head=head->next_task; 
 
                delete temp; 
 
                cout<<"Task deleted successfully."<<endl; 
                return; 
            } 
            Node* temp=head; 
 
            while(temp->next_task!= NULL) 
            { 
                if (temp->next_task->Task_ID == ID) 
                { 
                    Node* deleteNode = temp->next_task; 
                    temp->next_task = deleteNode->next_task; 
                    delete deleteNode; 
                    cout << "Task deleted successfully." << endl; 
                    return; 
                } 
                temp = temp->next_task; 
            } 
            cout << "Given Task ID not found." << endl; 
        } 
 
        void SearchUsingTaskID(int ID) 
        { 
            if (head == NULL) 
            { 
                cout << "List is empty. No task exists." << endl; 
                return; 
            } 
 
            Node * temp = head; 
 
            while (temp != NULL) 
            { 
                if (temp->Task_ID == ID) 
                { 
                    cout << "Task Found!" << endl; 
                    cout << "Task ID: " << temp->Task_ID << endl; 
                    cout << "Description: " << temp->Description << endl; 
                    cout << "Status: " << temp->status << endl; 
                    return; 
                }    
                temp = temp->next_task; 
            } 
            cout << "Given Task ID not found." << endl; 
        } 
         
        void DisplayPendingTasks() 
        { 
            if (head == NULL) 
            { 
                cout << "List is empty. No task exists." << endl; 
                return; 
            } 
 
            Node* temp = head; 
 
            while (temp != NULL) 
            { 
                if (temp->status == "Uncompleted") 
                { 
                    cout << "Task ID: " << temp->Task_ID << endl; 
                    cout << "Description: " << temp->Description << endl; 
                    cout << "Status: " << temp->status << endl; 
                    cout << "------------------------" << endl; 
                } 
 
                temp = temp->next_task; 
            } 
        } 
 
        void CountTasks() 
        { 
            int count = 0; 
            Node* temp = head; 
 
            while (temp != NULL) 
            { 
                count++; 
                temp = temp->next_task; 
            } 
            cout << "Total number of tasks: " << count << endl; 
        } 
 
        void MarkCompleted(int ID) 
        { 
            Node* temp = head; 
 
            while (temp != NULL) 
            { 
                if (temp->Task_ID == ID) 
                { 
                    cout << "Task Found!" << endl; 
                    cout << "Task ID: " << temp->Task_ID << endl; 
                    cout << "Description: " << temp->Description << endl; 
                    cout << "Current Status: " << temp->status << endl; 
 
                    char choice; 
                    cout << "Do you want to mark this task as completed? (y/n): "; 
                    cin >> choice; 
 
                    if (choice == 'y' || choice == 'Y') 
                    { 
                        temp->status = "Completed"; 
                        cout << "Task marked as completed successfully." << endl; 
                    } 
                    else 
                    { 
                        cout << "Task status was not changed." << endl; 
                    } 
                    return; 
                } 
                temp = temp->next_task; 
            } 
        cout << "Given Task ID does not exist." << endl; 
        } 
 
        void Display() 
        { 
            if (head == NULL) 
            { 
                cout << "List is empty. No task exists." << endl; 
                return; 
            } 
 
            Node* temp = head; 
 
            cout << "===== COMPLETED TASKS =====" << endl; 
 
            while (temp != NULL) 
            { 
                if (temp->status == "Completed") 
                { 
                    cout << "Task ID: " << temp->Task_ID << endl; 
                    cout << "Description: " << temp->Description << endl; 
                    cout << "------------------------" << endl; 
                } 
                temp = temp->next_task; 
            } 
 
            temp = head; 
 
            cout << endl << "===== UNCOMPLETED TASKS =====" << endl; 
 
            while (temp != NULL) 
            { 
                if (temp->status == "Uncompleted") 
                { 
                    cout << "Task ID: " << temp->Task_ID << endl; 
                    cout << "Description: " << temp->Description << endl; 
                    cout << "------------------------" << endl; 
                } 
                temp = temp->next_task; 
            } 
        }  
    }; 
 
    void menu() 
    { 
        cout<<endl<<"1. Add a new task at the beginning."<<endl; 
        cout<<"2. Add a task at the end"<<endl; 
        cout<<"3. Insert a task after a given Task ID."<<endl; 
        cout<<"4. Delete a task using Task ID."<<endl; 
        cout<<"5. Search for a task."<<endl; 
        cout<<"6. Display all pending tasks."<<endl; 
        cout<<"7. Count the number of tasks."<<endl; 
        cout<<"8. Mark a task as completed."<<endl; 
        cout<<"9. Display completed and pending tasks separately."<<endl; 
        cout<<"10. Exit."<<endl<<endl; 
    } 
 
    void getTaskInput(int &id, string &desc, string &status)  
    { 
        cout << "Enter the Task ID please: "; 
        cin >> id; 
        cout << "Enter the description please: "; 
        cin >> desc; 
        cout << "Enter the status please (Completed/Uncompleted): "; 
        cin >> status; 
    } 
 
    int main() 
    { 
        Task_Manager list; 
        int choice,ID; 
        string description,status; 
        do 
        { 
            menu(); 
            cout<<"Enter your choice please: "; 
            cin>>choice; 
            cout<<endl; 
 
            if(choice==1) 
            { 
                getTaskInput(ID, description, status); 
                list.InsertAtBeginning(ID,description,status); 
            } 
             
            else if(choice==2) 
            { 
                getTaskInput(ID, description, status); 
                list.InsertAtEnd(ID,description,status); 
            } 
 
            else if(choice==3) 
            { 
                int old_taskID; 
                cout<<"Enter Old Task ID please: "; 
                cin>>old_taskID; 
                getTaskInput(ID, description, status); 
                list.InsertAfterTaskID(old_taskID,ID,description,status); 
            } 
 
            else if(choice==4) 
            { 
                cout<<"Enter ID please: "; 
                cin>>ID; 
                list.DeleteUsingTaskID(ID); 
            } 
             
            else if(choice==5) 
            { 
                cout<<"Enter the ID please: "; 
                cin>>ID; 
                list.SearchUsingTaskID(ID); 
            } 
             
            else if(choice==6) 
            { 
                list.DisplayPendingTasks(); 
            } 
 
            else if(choice==7) 
            { 
                list.CountTasks(); 
            } 
 
            else if(choice==8) 
            { 
                cout<<"Enter the ID please: "; 
                cin>>ID; 
                list.MarkCompleted(ID); 
            } 
 
            else if(choice==9) 
            { 
                list.Display(); 
            } 
 
            else if(choice==10) 
            { 
                cout<<"Exiting..."; 
                return 0; 
            } 
 
            else 
            { 
                cout<<"Invalid Choice. Try again."<<endl; 
            } 
 
        } while (choice!=10); 
    } 