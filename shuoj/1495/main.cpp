#include<stdio.h>
int main()
{
	int a[1000],b[1000];
	int i=0,j;
	while(scanf("%d",&a[i])!=EOF)
		{
			b[i]=a[i]*(a[i]-1)*(a[i]-2)/6;
			printf("%d",b[i]);
		    printf("\n");	
			i++;
		}	
		
return 0;	
}
