#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i=0,w=0,x=0,y=0,z=0,m;
	while(gets(a))
	{
		m=strlen(a);
		for(i=0;i<m;i++)
		{
	if(a[i]>='a'&& a[i]<='z' || a[i]>='A'&& a[i]<='Z' )
		w++;
	else if(a[i]>='0'&& a[i]<='9')
        x++;
    else if(a[i]==' ')
        y++;
    else
        z++;		
		}
		printf("%d %d %d %d\n",w,x,y,z);
		w=x=y=z=0;
	}
	
	
	
	
	
	
	
return 0;	
}
