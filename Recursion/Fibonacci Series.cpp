#include<stdio.h>
int F[20];
int fib(int n)
{
	if(n<=1)
	{
		F[n] = n;
		return n;
	}
	if(F[n-2]==-1)
	{
		F[n-2] = fib(n-2);
	}
	if(F[n-1]==-1)
	{
		F[n-1] = fib(n-1);
	}
	return F[n-2] + F[n-1];
}
int main()
{
	int n=15;
	for(int i=0 ; i<20 ; i++)
	{
		F[i]=-1;
	}
	for(int i=0; i<=n ; i++)
	{
		printf("%d ",fib(i));
	}
}