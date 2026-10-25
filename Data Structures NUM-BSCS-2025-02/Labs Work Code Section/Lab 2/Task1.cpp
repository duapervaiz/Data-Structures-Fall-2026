#include<iostream> 
using namespace std; 
int main() 
{ 
    int size; 
    cout<<"Enter the size of matrix please: "; 
    cin>>size; 
    cout<<endl; 
    int matrix[size][size]; 
    for(int i=0;i<size;i++) 
    { 
        for(int j=0;j<size;j++) 
        { 
            cout<<"Enter ["<<i+1<<"]["<<j+1<<"] element of the matrix: "; 
            cin>>matrix[i][j]; 
        } 
        cout<<endl; 
    } 
     
    for(int i=0;i<size;i++) 
    { 
        for(int j=0;j<size;j++) 
        { 
            if(i!=j) 
            { 
                if(matrix[i][j]!=0) 
                { 
                    cout<<"Matrix is not diagonal...."<<endl; 
                    return 0; 
                } 
            } 
        } 
    } 
    cout<<"Matrix is diagonal.."<<endl; 
}