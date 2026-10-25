#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream file1("genome.txt");

    ofstream file2("genomecount.txt");

    char ch;
    int A=0, G=0, T=0, C=0;

    while(file1>>ch)
    {
        if(ch=='A')
            A++;
        else if(ch=='G')
            G++;
        else if(ch=='T')
            T++;
        else if (ch=='C')
            C++;
    }

    file2<<"A: "<<A<<" G: "<<G<<" T: "<<T<<" C: "<<C;
    cout<<"A = "<<A<<endl;
    cout<<"G = "<<G<<endl;
    cout<<"T = "<<T<<endl;
    cout<<"C = "<<C<<endl;


    file1.close();
    file2.close();

    return 0;
}
