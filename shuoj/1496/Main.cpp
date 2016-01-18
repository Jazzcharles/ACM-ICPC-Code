#include<stdio.h>
int main()
{
int n,i,a,b,c;
while(scanf("%d",&n)!=EOF)
{
a=n/100;
b=n%100/10;
c=n%10;
if(a*a*a+b*b*b+c*c*c==n)
 printf("%d:YES\n",n);
else
 printf("%d:NO\n",n);
}
	
	
	
	
	
return 0;
}
