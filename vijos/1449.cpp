#include <stdio.h>
#include <stdlib.h>
#include <cstring>	
char a[4][20000];
char b[4][20000];
char c[50][20000];
char d[50][20000];
int main()
{
	int n;
	int i,j,k,m;
	int temp;

	scanf("%d",&n);
	scanf("%s%s%s",a[0],a[1],a[2]);
	for(i=0;i<3;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[i][n-j-1];
		}
	}
	for(i=0;i<3;i++)
	{
		for(k=0;k<=6;k++)
		{
			for(j=0;j<n;j++)
			{
				temp=b[i][j]+k;
				if(temp>122) temp-=26;
				c[i][j]=temp;
				temp=b[i][j]-k;
				if(temp<97) temp+=26;
				d[i][j]=temp;
			}
			for(m=0;m<3;m++)
			{
				if(m!=i){
					if((strcmp(c[i],a[m])==0) && (strcmp(d[i],a[3-i-m])==0))
					{
						printf("%s",b[i]);
	
					}
				}
			}
		}
	}
	return 0;
}
