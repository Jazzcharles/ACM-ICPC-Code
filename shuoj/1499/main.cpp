#include<stdio.h>
int main()
{
	int a,b,c,x,y,z,i=1,flag=0;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		printf("Case %d:",i);
		printf("\n");
        for(x=1;x<=98;x++)
		{
		   for(y=98;y>=1;y--)
			{
			   z=100-x-y;
		       if(a*x+b*y+c*z*1.0/3==100)
			   { 
				   printf("%d %d %d\n",x,y,z);
				   flag=1;
				   break;
		       }
		    }
	    if(flag==1)
		   break;
		}
	   if(flag==0)
		   printf("Impossible\n");
	   i++;
	   flag=0;
	}
	
	return 0;
}
	