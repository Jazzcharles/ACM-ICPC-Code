#include<string.h>
#include<stdio.h>
int main()
{
	int i=0,j,n,k,flag=0,m,index,l,count=0;
    char ch,a[100],b[100];
    while(scanf("%s",&a)!=EOF)
	{
        scanf("%s",b);		
	    m=strlen(a);
		n=strlen(b);
			for(j=0;j<n;j++)
				if(a[i]==b[j])
				{
					  i++;
					  count++;
					  if(count==m)
						  {flag=1;break;}
				}
		if(flag==1)
			printf("Yes\n");
		if(flag==0)
			printf("No\n");
		flag=0;i=0;count=0;
	}
	return 0;
}
