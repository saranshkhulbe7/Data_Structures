#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p = (int *)malloc(5*sizeof(int));
    p[0]=3;p[1]=3;p[2]=7;p[3]=9;p[4]=11;
    
    int *q = (int *)malloc(10*sizeof(int));
//    for(int i=0;i<5;i++)
//    {
//        q[i]=p[i];
//    }
    memcpy(q,p,sizeof(*p)*5);
    free(p);
    p=q;
    q=NULL;
     p[5]=13;p[6]=15;p[7]=17;p[8]=19;p[9]=21;
    for(int i=0;i<10;i++)
    {
        printf("%d ",p[i]);
    }
}
