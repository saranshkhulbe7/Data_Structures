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
    int count=1;
    Node *q=NULL;
    while(p)
    {
        if(key==p->data)
        {
            if(count!=1)
            {
                q->next=p->next;
                p->next=head;
                head=p;
            }
            return p;
        }
        else
        {
            q=p;
            p=p->next;
            count++;
        }
    }
    return NULL;
}

void Display(Node *p)
{
    cout<<endl;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
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
    cout<<"\nPicture Of List Before First Search :-";
    Display(head);
    element=LinearSearch(head,key);
    if(element!=NULL)
    {
        cout<<"\nElement Found At Address : "<<element<<"\n";
    }
    else
    {
        cout<<"\nElement Not Found\n";
    }
    cout<<"\nPicture Of List Before Second Search :-";
    Display(head);
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
