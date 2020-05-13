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

void Insert(Node *p,int index,int x)
{
    if(index == 0)
    {
        Node *t = new Node;
        t->data=x;
        t->next=head;
        head = t;
    }
    else if(index > 0)
    {
        for(int i=1;i<=index-1 && p!=NULL ;i++)
        {
            p=p->next;
        }
        Node *t = new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
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
    int index;
    int value;
    cout<<"Enter The Number Of Elements : ";
    cin>>n;
    A = new int[n];
    Fill(A,n);
    Create(A,n);
    Display(head);
    cout<<"Enter Value To Be Inserted : ";
    cin>>value;
    cout<<"Enter The Position Of Insertion : ";
    cin>>index;
    Insert(head,index,value);
    Display(head);
    return 0;
}
