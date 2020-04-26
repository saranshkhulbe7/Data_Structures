#include<iostream>
using namespace std;

void Swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Transpose(int **A,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            Swap(A[i][j],A[j][i]);
        }
    }
}

void Display(int **A,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int **A;
    int n;
    cout<<"Enter The Order Of The Matrix : ";
    cin>>n;
    A = new int*[n];
    for(int i=0;i<n;i++)
    {
        A[i] = new int [n];
    }
    cout<<"Enter The Matrix :- \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter Element At A["<<i+1<<"]["<<j+1<<"] : ";
            cin>>A[i][j];
        }
    }
    cout<<"\nOriginal Matrix :- \n";
    Display(A,n);
    Transpose(A,n);
    cout<<"\nTransposed Matrix :- \n";
    Display(A,n);
}
