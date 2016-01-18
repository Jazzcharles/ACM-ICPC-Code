#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char x[maxn],y[maxn];
int Next[maxn],Extend[maxn];

//bababababababb
//bababb  

void pre_EKMP(char x[],int m,int next[])
{
	next[0]=m;
	int j=0;
	while(j+1<m && x[j]==x[j+1])j++;
	next[1]=j;
	int k=1;
	for(int i=2;i<m;i++)
	{
		int p=next[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)   next[i]=L;
		else
		{
			j=max(0,p-i+1);
			while(i+j<m && x[i+j]==x[j])j++;
			next[i]=j;
			k=i;
		}
	}
}

int EKMP(char x[],int m,char y[],int n,int next[],int extend[])
{
	pre_EKMP(x,m,next);
	int j=0;
	while(j<n && j<m && x[j]==y[j])j++;
	extend[0]=j;
	int k=0;
	for(int i=1;i<n;i++)
	{
		int p=extend[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)extend[i]=L;
		else
		{
			j=max(0,p-i+1);
			while(i+j<n && j<m && y[i+j]==x[j])j++;
			extend[i]=j;
			k=i;
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++)
		ans=max(ans,extend[i]);
	return ans;
}



int main(int argc, char** argv) {
	while(gets(y)){
		memset(Extend,0,sizeof(Extend));
		memset(Next,0,sizeof(Next));
		gets(x);
		int lenx=strlen(x);
		int leny=strlen(y);
		printf("%d\n",EKMP(x,lenx,y,leny,Next,Extend));
		getchar();
//		if(lens<leno) swap(str,opt);
//		printf("%d\n",kmp());
	}
	return 0;
}
