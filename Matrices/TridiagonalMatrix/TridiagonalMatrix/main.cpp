#include<iostream>
using namespace std;

class Matrix
{
    int n;
    int *A;
public:
    Matrix();
    Matrix(int n);
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void SetMatrix();
    void Display();
    ~Matrix();
};

Matrix::Matrix()
{
    n=5;
    A = new int[n+2*(n-1)];
}
 Matrix::Matrix(int n)
{
    this->n=n;
    A = new int[n+2*(n-1)];
}
void Matrix::Set(int i,int j,int x)
{
    if(i-j==1)
    {
        A[i-2]=x;
    }
    else if(i-j==0)
    {
        A[n-1+i-1]=x;
    }
    else if(i-j==-1)
    {
        A[2*n-1+i-1]=x;
    }
}

int Matrix::Get(int i,int j)
{
    if(i-j==1)
    {
        return A[i-2];
    }
    else if(i-j==0)
    {
        return A[n-1+i-1];
    }
    else if(i-j==-1)
    {
        return A[2*n-1+i-1];
    }
    else
    {
        return 0;
    }
}

void Matrix::SetMatrix()
{
    int x;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            for(int j=1;j<3;j++)
            {
                cout<<"Enter Element At A["<<i<<"]["<<j<<"] ";
                cin>>x;
                Set(i,j,x);
            }
        }
        else if(i<n)
        {
            for(int j=i-1;j<=i+1;j++)
            {
                cout<<"Enter Element At A["<<i<<"]["<<j<<"] ";
                cin>>x;
                Set(i,j,x);
            }
        }
        else
        {
            for(int j=n-1;j<=n;j++)
            {
                cout<<"Enter Element At A["<<i<<"]["<<j<<"] ";
                cin>>x;
                Set(i,j,x);
            }
        }
        
    }
}

void Matrix::Display()
{
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<Get(i,j)<<" ";
        }
        cout<<endl;
    }
}

Matrix::~Matrix()
{
    delete []A;
}

int main()
{
    Matrix m;
    m.SetMatrix();
    m.Display();
}
