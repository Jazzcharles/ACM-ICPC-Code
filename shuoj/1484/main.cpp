#include<stdio.h>
int GCD(int a,int b);
int main()
{
	int i,a,b,c,d,e,f;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
	i++;
	e=(a>0)?a:-a;
	f=(b>0)?b:-b;
	c=GCD(e,f);
	d=e*f/c;
	printf("Case %d:\n",i);
	 if(a!=0 && b!=0)
     {
	 printf("GCD(%d,%d) = %d\n",a,b,c);
	 printf("LCM(%d,%d) = %d\n",a,b,d);
	 }
	 else if(a!=0 || b!=0)
	 {
	  printf("GCD(%d,%d) = %d\n",a,b,(a<b)?b:a);
	  printf("no LCM\n");
	 }
	 else
		{
		   printf("no GCD\n");
	       printf("no LCM\n");
	    }
	 printf("\n");
	}
	
		   return 0;
}
