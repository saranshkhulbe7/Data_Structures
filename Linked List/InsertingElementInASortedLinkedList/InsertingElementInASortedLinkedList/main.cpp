#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*head;

void Fill (int *A, int n)
{
 for(int i=0;i<n;i++)
 {
     cin>>A[i];
 }
}

void Create(int *A,int n)
{
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    Node *last = head,*t;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Insert(Node *p,int x)
{
    Node *q = NULL,*t;
    if(head == NULL)
    {
        t = new Node;
        t->data = x;
        t->next = NULL;
        head = t;
    }
    else if(head->data>x)
    {
        t = new Node;
        t->data = x;
        t->next = head;
        head = t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        t = new Node;
        t->data = x;
        t->next = q->next;
        q->next = t;
    }
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
    int value;
    cout<<"Enter The Number Of Elements : ";
    cin>>n;
    A = new int[n];
    Fill(A,n);
    Create(A,n);
    Display(head);
    cout<<"Enter Value To Be Inserted : ";
    cin>>value;
    Insert(head,value);
    Display(head);
    return 0;
}
