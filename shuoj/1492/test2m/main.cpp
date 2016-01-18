#include<stdio.h>
void sort(int c[],int n);
int main()
{
	int a[100],b[100],i,n,s=0;
    while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
	    for(i=0;i<n;i++)
			scanf("%d",&b[i]);
	    sort(a,n);
		sort(b,n);
	    for(i=0;i<n;i++)
			s+=a[i]*b[i];
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
	
	void sort(int c[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(c[j]>c[j+1])
			{temp=c[j];c[j]=c[j+1];c[j+1]=temp;}
}
