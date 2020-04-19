#include<stdio.h>
int c(int n,int r)
{
	if(r==0||r==n)
	{
		return 1;
	}
	return c(n-1,r-1)+c(n-1,r);
}
int main()
{
	printf("%d ",c(4,3));
}