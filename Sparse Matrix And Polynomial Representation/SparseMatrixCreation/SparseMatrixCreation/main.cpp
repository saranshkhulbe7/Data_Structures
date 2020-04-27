#include<iostream>
using namespace std;

class Element
{
public:
    int i;        //row number
    int j;        //column number
    int x;        //element
};

class Sparse
{
public:
    int m;                          //total rows
    int n;                          //total column
    int num;                        //total non-zero elements
    Element *ele;            //to create the array of struct Element
    void Create(Sparse *s);
};

void Sparse::Create(Sparse *s)
{
    cout<<"Enter Dimensions :- \n";
    cout<<"Rows : ";
    cin>>s->m;
    cout<<"Columns : ";
    cin>>s->n;
    cout<<"Enter The Total Number Of Non-Zero Elements : ";
    cin>>s->num;
    
    s->ele= new Element[num];
    cout<<"\nEnter All Non-Zero Elements\n";
    for(int i=0;i<s->num;i++)
    {
        cout<<"\n";
        cout<<"Enter Row Number Of Element "<<i+1<<" : ";
        cin>>s->ele[i].i;
        cout<<"Enter Column Number Of Element "<<i+1<<" : ";
        cin>>s->ele[i].j;
        cout<<"Enter Element : ";
        cin>>s->ele[i].x;
    }
}

void Display(Sparse s)
{
    cout<<"\n";
    int k=0;
    for(int p=1;p<=s.m;p++)
    {
        for(int q=1;q<=s.n;q++)
        {
            if(p==s.ele[k].i && q==s.ele[k].j)
            {
                cout<<s.ele[k++].x<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        printf("\n");
    }
}

int main()
{
    Sparse s;
    s.Create(&s);
    Display(s);
    return 0;
}
