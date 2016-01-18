#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,j=0,k,l,a[1000],n,flag=0,index,temp,m;
  scanf("%d",&n);  
  for(i=1;i<=n;i++)
  {
	scanf("%d",&m);
	for(j=0;j<m;j++)
	   scanf("%d",a[j]);
	  

	for(k=0;k<j;k++)
		  index=k;
	      for(l=k+1;l<j;l++)
			  index=l;
		  if(a[k]<a[index])
			  {temp=a[k];a[k]=a[index];a[index]=temp;}
		  
	  for(k=0;k<=j-2;k++)
		  if(a[k+2]-a[k+1]==a[k+1]-a[k])
			  flag=1;
		  else
			  {flag=0;break;}
	  if(flag==1)
		  printf("yes\n");
	  else
		  printf("no\n");
	}
	return 0;
}
