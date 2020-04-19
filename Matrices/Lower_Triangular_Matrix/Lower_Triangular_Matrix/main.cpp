#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Matrix
{
    int n;
    int *A;
};

int Sum(int n)
{
    return (n*(n+1))/2;
}

void Set(struct Matrix *m, int i,int j, int x)
{
    if(i>=j)
        m->A[(Sum(i-1)+j)-1] = x;
}

int Get(struct Matrix *m,int i,int j)
{
    if(i>=j)
        return m->A[(Sum(i-1)+j)-1];
    else
        return 0;
}

void Display(struct Matrix *m)
{
    for(int i=1;i<=m->n;i++)
    {
        for(int j=1;j<=m->n;j++)
        {
            printf("%d  ",Get(m,i,j));
        }
        printf("\n");
    }
}

void DefaultSet(struct Matrix *m)
{
    for(int i=0;i<Sum(m->n);i++)
        m->A[i]=0;
}
int main()
{
    struct Matrix m = {5};
    m.A = (int *)malloc(Sum(m.n) * sizeof(int));
    DefaultSet(&m);
    Set(&m,1,1,1);
    Set(&m,2,1,2);
    Set(&m,2,2,3);
    Set(&m,3,1,4);
    Set(&m,3,2,5);
    Set(&m,3,3,6);
    Set(&m,4,1,7);
    Set(&m,4,2,8);
    Set(&m,4,3,9);
    Set(&m,4,4,5);
    Set(&m,5,1,1);
    Set(&m,5,2,2);
    Set(&m,5,3,8);
    Set(&m,5,4,7);
    Set(&m,5,5,6);
    Display(&m);
    free(m.A);
}
