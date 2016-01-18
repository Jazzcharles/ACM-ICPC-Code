#include<stdio.h>
int main()
{
	int n,i,j,a[100];
	char ch;
	while(scanf("%d",&n)!=EOF)
	{
        ch=getchar();
		for(i=0;n!=0;i++)
		{
			a[i]=n%3;
		    n=n/3;
		}
	    for(j=i-1;j>=0;j--)
			putchar(a[j]+'0');
		printf("\n");
	}	
return 0;	
}

