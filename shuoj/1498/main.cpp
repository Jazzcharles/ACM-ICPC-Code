#include<stdio.h>
int fun(int n);
int main()
{
 int x,i=0,flag;
 while(scanf("%d",&x)!=EOF)
 {
	 flag=fun(x);
	 if(flag==1)
		 printf("%d YES\n",x);
	 else
		 printf("%d NO\n",x);
 } 
	
return 0;
}

int fun(int n)
{
	int i,s=0;
	for(i=1;i<=n/2;i++)
		if(n%i==0)
	     s=s+i;
	if(s==n)
		return 1;
	else
		return 0;
	
	
}
