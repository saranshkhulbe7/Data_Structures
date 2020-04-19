#include<stdio.h>
void TOH(int n,int A,int B,int C)
{
	if(n==1)
	{
		printf("from %d to %d\n",A,C);
	}
	if(n>1)
	{
		TOH(n-1,A,C,B);
	    printf("from %d to %d\n",A,C);
	    TOH(n-1,B,A,C);
	}
}

int main()
{
	TOH(3,1,2,3);
}