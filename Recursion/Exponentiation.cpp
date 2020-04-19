#include<stdio.h>
int e(int m,int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n%2==0)
	{
		return e(m*m,n/2);
	}
	else
	{
		return m * e(m*m,(n-1)/2);
	}
}
int main()
{
	printf("%d ",e(2,7));
}