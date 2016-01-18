#include<stdio.h>
void create(int b[],int i);
void sort(int c[],int i);
int main()
{
	int a[1000],i=0,k,j,n;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
	   while(1)
       {
       scanf("%d",&a[i]);
	   i++;
	   if(getchar()=='\n')
	   break;
	   }
	   create(a,i);
	   printf("Case %d\n",k);
	   printf("Before sorting:\n");
	   for(j=0;j<i;j++)
	   {
		   printf("%d ",a[j]);
	       if((j+1)%10==0 && j!=0)
		   printf("\n");
	   }
	   printf("\n");
	   sort(a,i);
	   printf("After sorting:\n");
	   	   for(j=0;j<i;j++)
	   {
		   printf("%d ",a[j]);
	       if((j+1)%10==0 && j!=0)
		   printf("\n");
	   }
		   printf("\n");
		i=0;
	}
	return 0;
}
void create(int b[],int i)
{
	int j,temp;
	for(j=0;j<i/2;j++)
		{
		temp=b[j];
	    b[j]=b[i-1-j];
		b[i-1-j]=temp;
	    }
}

 void sort(int c[],int i)
 {
	int j,k,temp;
    for(j=1;j<i;j++)
       for(k=0;k<i-j;k++)
          if(c[k]<c[k+1])
          {
 			  temp=c[k];
			  c[k]=c[k+1];
			  c[k+1]=temp;
		  }
	
 }
 