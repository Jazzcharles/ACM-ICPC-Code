#include<stdio.h>
int main()
{
	int i=0,j=0,k,x=1,n;
	int a[100][100]={0};
    while(scanf("%d",&n)!=EOF)
	{
		
		for(k=0;k<=n/2;k++)
		{
			for(j=k;j<=n-k-1;j++)
			{
				a[k][j]=x;
			    x++;
			}
		    for(i=k+1;i<=n-k-1;i++)
			{
				a[i][n-k-1]=x;
			    x++;
			}
		    for(j=n-k-2;j>=k;j--)
			{
				a[n-k-1][j]=x;
			    x++;
		    }
		    for(i=n-k-2;i>k;i--)
			{
				a[i][k]=x;
			    x++;
	        }
		}	
		for(i=0;i<n;i++)
		{
			printf("%d",a[i][0]);
			for(j=1;j<n;j++)
					printf(" %d",a[i][j]);
			printf("\n");
		}
		printf("\n");
		
		i=0;j=0;x=1;
	
	}
	return 0;
}
