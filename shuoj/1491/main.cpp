#include<stdio.h>
void array(int b[],int n);
void sort(int d[],int n);
int main()
{
	int a[1000],n,i;
	while(scanf("%d",&n)!=EOF)
	{
	a[0]=25;
	a[1]=-25;
	array(a,n);
	sort(a,n);
	printf("%d",a[0]);
    for(i=1;i<n;i++)
      printf(" %d",a[i]);
    printf("\n");	
	}
return 0;	
}


void array(int b[],int n)
{
	int j;
	for(j=2;j<n;j++)
	b[j]=(b[j-1]*4627+b[j-2]*3581)/100%100-50;
	
}

void sort(int d[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	  for(j=0;j<n-i;j++)
		  if(d[j]>d[j+1])
		  {
			  temp=d[j];
			  d[j]=d[j+1];
			  d[j+1]=temp;
		  }
	
}
