#include<iostream>
#include<math.h>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    Term *t;
};

void Create(Poly &p)
{
    cout<<"\n   Enter Number Of Terms :- ";
    cin>>p.n;
    p.t = new Term[p.n];
    
    for(int i=0;i<p.n;i++)
    {
        cout<<"Enter Coefficient Of Term "<<i+1<<" :- ";
        cin>>p.t[i].coeff;
        cout<<"Enter Exponent Of Term "<<i+1<<" :- ";
        cin>>p.t[i].exp;
    }
}

void Display(Poly p)
{
    cout<<endl;
    for(int i=0;i<p.n;i++)
    {
        if(p.t[i].coeff>=0)
        {
            if(i!=0)
            {
                cout<<"+";
            }
            cout<<p.t[i].coeff<<"x^"<<p.t[i].exp;
        }
        else
        {
            cout<<p.t[i].coeff<<"x^"<<p.t[i].exp;
        }
    }
    cout<<endl;
}

void Add(Poly &p3,Poly p1,Poly p2)
{
    p3.n = p1.n + p2.n;
    p3.t=new Term[p3.n];
    int i=0,j=0,k=0;
    while(i<p1.n && j<p2.n)
    {
        if(p1.t[i].exp>p2.t[j].exp)
        {
            p3.t[k++]=p1.t[i++];
        }
        else if(p1.t[i].exp<p2.t[j].exp)
        {
            p3.t[k++]=p2.t[j++];
        }
        else
        {
            p3.t[k]=p1.t[i++];
            p3.t[k++].coeff+=p2.t[j++].coeff;
        }
    }
    while(i<p1.n)
    {
        p3.t[k++]=p1.t[i++];
    }
    while(j<p2.n)
    {
         p3.t[k++]=p2.t[j++];
    }
    p3.n=k;
    cout<<"\n\nAddition Done Successfully\n";
}

int eval(Poly p,int x)
{
    int sum=0;
    for(int i=0;i<p.n;i++)
    {
        sum += p.t[i].coeff*pow(x,p.t[i].exp);
    }
    return sum;
}
int main()
{
    Poly p1,p2,p3;
    Create(p1);
    Display(p1);
    Create(p2);
    Display(p2);
    Add(p3,p1,p2);
    Display(p3);
    int x;
    cout<<"\n\nNow Give The Value Of x :- ";
    cin>>x;
    cout<<"P("<<x<<")="<<eval(p3,x);
    cout<<"\n\n";
}
