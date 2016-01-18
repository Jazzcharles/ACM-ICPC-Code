#include<stdio.h>
#include<string.h>
int palindrome(char* s,int m);
int main()
{
	char a[1000],ch;
	int i,flag,n,m;
	scanf("%d",&n);
	ch=getchar();
	for(i=1;i<=n;i++)
	{
	gets(a);
	m=strlen(a);
	flag=palindrome(a,m);
	if(flag==1)
		printf("YES!\n");
	else
		printf("NO!\n");
	}
return 0;	
}
int palindrome(char* s,int m)
{
	char *p;
	for(p=s+m-1;s<=p;s++,p--)
		if(*s!=*p)
		return 0;
	return 1;
	
}
