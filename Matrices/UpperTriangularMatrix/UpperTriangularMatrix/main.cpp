#include<iostream>
using namespace std;

int Sum(int n)
{
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=i;
    }
    return sum;
}

class Matrix
{
public:
    int n;
    int *A;
    
public:
    Matrix();
    Matrix(int n);
    void Set(int i,int j,int x);             //x is the element we want to enter
    int Get(int i, int j);
    void SetMatrix();
    void Display();
    ~Matrix();
};

Matrix::Matrix()
{
    n=5;
    A = new int[Sum(n)];
    for(int i=0;i<Sum(n);i++)
    {
        A[i]=0;
    }
}

Matrix::Matrix(int n)
{
    this->n=n;
    A = new int[Sum(n)];
    for(int i=0;i<Sum(n);i++)
    {
        A[i]=0;
    }
}

void Matrix::Set(int i,int j,int x)
{
    if(j>=i)
       A[Sum(j-1)+i-1] = x;
}

int Matrix::Get(int i,int j)
{
    if(j>=i)
        return A[Sum(j-1)+i-1];
    else
        return 0;
}

void Matrix::SetMatrix()
{
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            cout<<"\nEnter Element At A["<<i<<"]["<<j<<"] ";
            cin>>x;
            Set(i,j,x);
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
    Matrix m(4);
    m.SetMatrix();
    m.Display();
}
