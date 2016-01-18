#include<stdio.h>
int main()
{
	int i,j,m,a,b,s2=0,s1=0;
	scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
    	scanf("%d %d",&a,&b);
        for(j=1;j<=a/2;j++)
			if(a%j==0)
				s1+=j;
		for(j=1;j<=b/2;j++)
			if(b%j==0)
				s2+=j;
	    if(s1==b && s2==a)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
