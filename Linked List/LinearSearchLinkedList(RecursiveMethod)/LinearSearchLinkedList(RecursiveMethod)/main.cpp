#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*head,*last;

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
    last=head;
    Node *t;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

Node * LinearSearch(Node *p,int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        if(key==p->data)
        {
            return p;
        }
        return LinearSearch(p->next,key);
    }
}


int main()
{
    int *A,n;
    cout<<"Enter The Number Of Element : ";
    cin>>n;
    A=new int[n];
    Fill(A,n);
    Create(A,n);
    Node *element;
    int key;
    cout<<"Enter The Key : ";
    cin>>key;
    element=LinearSearch(head,key);
    if(element!=NULL)
    {
        cout<<"\nElement Found At Address : "<<element<<"\n";
    }
    else
    {
        cout<<"\nElement Not Found\n";
    }
}
