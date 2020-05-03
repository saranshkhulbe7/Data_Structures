#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
}*head;

void Create(int *A,int n)
{
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    Node *last = head,*t;
    for(int i=1;i<n;i++)
    {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void fill(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
}

int Count(Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}


int main()
{
    int *A,n;
    cout<<"Enter The Number Of Elements : ";
    cin>>n;
    A = new int[n];
    fill(A,n);
    Create(A,n);
    cout<<"Total Nodes : "<<Count(head);
    cout<<endl;
    
}

