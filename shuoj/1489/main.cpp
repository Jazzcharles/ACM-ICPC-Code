#include<string.h>
#include<stdio.h>
int main()
{
int n,i,j,m,ch;
char a[1000];
scanf("%d",&n);
ch=getchar();
for(i=1;i<=n;i++)
{
	scanf("%s",a);
	m=strlen(a);
	for(j=m-1;j>=0;j--)
	printf("%c",a[j]);
	printf("\n");
}	
return 0;	
}
