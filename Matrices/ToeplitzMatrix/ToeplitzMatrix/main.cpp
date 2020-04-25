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
    void SetMatrix();
    int Get(int i,int j);
    void Display();
    ~Matrix();
};

Matrix::Matrix()
{
    n=5;
    A = new int [2*n-1];
}

Matrix::Matrix(int n)
{
    this->n=n;
    A = new int [2*n-1];
}
void Matrix::Set(int i,int j,int x)
{
    if(i<=n&&i>0&&j>0&&j<=n)
    {
        if(i<=j)
        {
            A[j-i]=x;
        }
        else
        {
            A[n+i-j-1]=x;
        }
    }
}

void Matrix::SetMatrix()
{
    int x;
    for(int j=1;j<=n;j++)
    {
        cout<<"Enter The Element At M[1]["<<j<<"] : ";
        cin>>x;
        Set(1,j,x);
    }
    for(int i=2;i<=n;i++)
    {
        cout<<"Enter The Element At M["<<i<<"][1] : ";
        cin>>x;
        Set(i,1,x);
    }
}

int Matrix::Get(int i,int j)
{
    if(i<=j)
        {
            return A[j-i];
        }
    else
        {
            return A[n+i-j-1];
        }
}

void Matrix::Display()
{
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
