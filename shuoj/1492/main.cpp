
#include<stdio.h>
int main()
{
  int n,m,i,j,k=1,a,b,x=0,y=0,flag=0;
  while(scanf("%d %d",&m,&n)!=EOF)
  {
   if(m==0 && n==0)
    break;
   for(i=0;a[i-1]!=-1;i++)
    scanf("%d %d",&a,&b);
   printf("Case %d:\n",k);
   for(j=0;j<i-1;j++)
   { 
	if(x>n && y>m-n)
      break;
    if(x>n && b[j]==1)
     continue;
    if(a[j]==1 && x<=n)
     {printf("Smoking: %d\n",x);x++;}
    if(a[j]==0 && y<=m-n || x>n && b[j]==0 && y<=m-n && a[j]==1)
	{printf("No Smoking: %d\n",y);y++;}

   }   
 k++;
 x=1;y=1;
}
 return 0;
}

