#include<stdio.h>
int main()
{
   int n,i,s,x,z,y,q,h,j=1;
   char a[100],ch;
   while(scanf("%d",&n)!=EOF)
   {
	ch=getchar();
	s=1;q=2;y=3;x=6;h=5;z=4;
    for(i=0;i<=n;i++)
	{
        scanf("%c",&a[i]);
    	if(a[i]=='E')
		{z=x;x=y;y=s;s=7-x;}
		else if(a[i]=='S')
		{h=x;x=q;q=s;s=7-x;}
		else if(a[i]=='W')
		{y=x;x=z;z=s;s=7-x;}
		else if(a[i]=='N')
		{q=x;x=h;h=s;s=7-x;}
	}
	   printf("Case %d:",j);
	   printf("%d\n",s);
	   j++;
   }
return 0;	
}
