#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,x,y,d;
	int num=1;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		x=a;y=b;
		printf("Case %d:\n",num);
		num++;
	if(x==0 && y==0)
	{
		printf("no GCD\n");
		printf("no LCM\n");
		printf("\n");
	}
	else
	{
		while(b!=0)
		{c=a%b;a=b;b=c;}
		a=(a>0)?a:-a;
		printf("GCD(%d,%d) = %d\n",x,y,a);
		d=x*y/a;
		d=(d>0)?d:-d;
		if(d!=0)
			printf("LCM(%d,%d) = %d\n",x,y,d);
	    else 
			printf("no LCM\n");
		printf("\n");
	}
	}
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
