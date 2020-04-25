#include<iostream>
using namespace std;

int StartPoint,EndPoint;

void fill(int *A,int n)
{
    cout<<"\nFill The Array\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element at index "<<i<<" : ";
        cin>>A[i];
    }
}


bool Check(int *A,int n,int k)
{
    int sum;
    for(int i=0;i<n;i++)
    {
        sum = 0;
        for(int j=i;j<n;j++)
        {
            sum+=A[j];
            if(sum==k)
            {
                StartPoint = i;
                EndPoint = j;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int *A,n,k;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    A = new int[n];
    cout<<"Enter the sum you want to achieve : ";
    cin>>k;
    fill(A,n);
    bool check = Check(A,n,k);
    if(check==true)
    {
        cout<<"\nSubset Found!\n";
        cout<<"{";
        for(int i=StartPoint;i<=EndPoint;i++)
        {
            if(i!=EndPoint) cout<<A[i]<<",";
            else cout<<A[i];
        }
        cout<<"}\n";
    }
    else
    {
        cout<<"Not Found\n";
    }
}
