#include<iostream>
using namespace std;

int Sum(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i;
    }
    return sum;
}

class Matrix
{
    int n;
    int *A;
public:
    Matrix();
    Matrix(int n);
    void Set(int i,int j,int x);   //x is the element which we want to enter
    int Get(int i,int j);
    void SetMatrix();
    void Display();
    ~Matrix();
};

Matrix::Matrix()
{
    n=5;
    A = new int[Sum(n)];
}

Matrix::Matrix(int n)
{
    this->n=n;
    A = new int (Sum(n));
}

void Matrix::Set(int i,int j,int x)
{
    if(j<=i)
        A[Sum(i-1)+j-1] = x;
}

int Matrix::Get(int i,int j)
{
    if(j<=i)
        return A[Sum(i-1)+j-1];
    else
        return Get(j,i);
}

void Matrix::SetMatrix()
{
    int x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
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
    Matrix m;
    m.SetMatrix();
    m.Display();
    
}
