#include<stdio.h>
int main()
{
	int i,a,b,n,s=0;
	scanf("%d %d",&a,&n);
	b=a;
	for(i=1;i<=n;i++)
	{
		s+=a;
		a=a*10+b;
	}
	printf("%d",s);

	return 0;
}
