#include<iostream>
using namespace std;

class Elements
{
public:
    int r;
    int c;
    int x;
};

class Sparse
{
public:
    int m;
    int n;
    int num;
    Elements *e;
    void Create();
    void Display();
    void Add(Sparse s1,Sparse s2);
};

void Sparse::Create()
{
    cout<<"\n\nEnter the Total Number Of Rows : ";
    cin>>m;
    cout<<"Enter the Total Number Of Columns : ";
    cin>>n;
    cout<<"Enter the Total Number Of Non-Zero Elements : ";
    cin>>num;
    e = new Elements[num];
    for(int i=0;i<num;i++)
    {
        cout<<endl;
        cout<<"Enter Row Number : ";
        cin>>e[i].r;
        cout<<"Enter Column Number : ";
        cin>>e[i].c;
        cout<<"Enter Element : ";
        cin>>e[i].x;
    }
}

void Sparse::Display()
{
    cout<<endl;
    int k=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(e[k].r==i &&e[k].c==j)
            {
                cout<<e[k++].x<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}

void Sparse::Add(Sparse s1,Sparse s2)
{
    if(s1.m!=s2.m || s1.n!=s2.n)
    {
        cout<<"Incompatible Dimensions For Addition";
    }
    else
    {
        m=s1.m;
        n=s1.n;
        num=s1.num+s2.num;
        e = new Elements[num];
        
        int i=0,j=0,k=0;
        while(i<s1.num&&j<s2.num)
        {
            if(s1.e[i].r<s2.e[j].r)
            {
                e[k]=s1.e[i];
                k++;
                i++;
            }
            else if(s1.e[i].r>s2.e[j].r)
            {
                e[k]=s2.e[j];
                k++;
                j++;
            }
            else
            {
                if(s1.e[i].c<s2.e[j].c)
                {
                    e[k]=s1.e[i];
                    k++;
                    i++;
                }
                else if(s1.e[i].c>s2.e[j].c)
                {
                    e[k]=s2.e[j];
                    k++;
                    j++;
                }
                else
                {
                    e[k].r=s1.e[i].r;
                    e[k].c=s1.e[i].c;
                    e[k].x=s1.e[i].x+s2.e[j].x;
                    k++;
                    i++;
                    j++;
                }
            }
        }
        while(i<s1.num)
        {
            e[k]=s1.e[i];
            k++;
            i++;
        }
        while(j<s2.num)
        {
            e[k]=s2.e[j];
            k++;
            j++;
        }
        num=k;
        cout<<"\nAddition Done Successfully";
    }
}

int main()
{
    Sparse s1,s2,s3;
    cout<<"Enter First Matrix :- ";
    s1.Create();
    s1.Display();
    cout<<"\nEnter Second Matrix :- ";
    s2.Create();
    s2.Display();
    s3.Add(s1,s2);
    cout<<"Resultant Matrix :- ";
    s3.Display();
}
