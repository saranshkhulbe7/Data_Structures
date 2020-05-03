#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*head;


void Fill(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
}

void Create(int *A,int n)
{
    head = new Node;
    head->data=A[0];
    head->next=NULL;
    Node *last=head,*t;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int Max(Node *p)
{
    static int max=p->data;
    if(p==NULL)
    {
        return max;
    }
    else
    {
        if(p->data>max)
        {
            max=p->data;
        }
        return Max(p->next);
    }
}

int main()
{
    int *A,n;
    cout<<"Enter The Number Of Elements : ";
    cin>>n;
    A = new int[n];
    Fill(A,n);
    Create(A,n);
    cout<<"Max is : "<<Max(head);
    cout<<endl;
}
