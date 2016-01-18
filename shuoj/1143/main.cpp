#include<stdio.h>
#include<stdlib.h>
int main()
{
	int f[1000],g[1000],m,n,i,j,min;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%d",&f[i]);
	for(i=0;i<n;i++)
		scanf("%d",&g[i]);
	min=abs(f[0]-g[0]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(abs(f[i]-g[j])<=min)
			{
				min=abs(f[i]-g[j]);
		    }
	
	printf("%d",min);
	return 0;
}
