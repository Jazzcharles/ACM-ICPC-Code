#include<stdio.h>
int main()
{
	int i,n,sum=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<n;i++)
		 sum=(sum+1)*2;
		printf("%d\n",sum);
		sum=1;
	}
return 0;
}
