#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first;



void fill(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
}


void Create(int *A,int n)
{
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    struct Node *t,*last;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *first)
{
    struct Node *t;
    t=first;
    while(t->next!=NULL)
    {
        printf("%d -> ",t->data);
        t=t->next;
    }
    printf("%d\n",t->data);
}


int main()
{
    int *A,n;
    printf("Enter The Number Of Elements : ");
    scanf("%d",&n);
    A=(int*)malloc(n*sizeof(int));
    fill(A,n);
    Create(A,n);
    Display(first);
}
