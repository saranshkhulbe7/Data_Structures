#include<iostream>
using namespace std;

int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

long Candies(int *A,int n)
{
    int c=0;
    int *C = new int [n];
    for(int i=0;i<n;i++)
    {
        C[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
        {
            C[i]=C[i-1]+1;
        }
    }
    
    for(int i=n-2;i>=0;i--)
    {
         if(A[i]>A[i+1])
         {
             C[i]=Max(C[i+1]+1,C[i]);
         }
    }
    for(int i=0;i<n;i++)
    {
        c+=C[i];
    }
    return c;
}

int main()
{
    int n;
    cout<<"Enter the number of students :-\n";
    cin>>n;
    int *A = new int [n];
    cout<<"Enter the ratings of the students :-\n";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"You need minimum "<<Candies(A,n)<<" Candies\n";
}
