#include<iostream>
#include<cstdio>
#include<cstring>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=32005;
int bit[maxn],ans[maxn],n;
int query(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int i,int x)
{
	while(i<=maxn)
	{
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int main(){
	while(cin>>n)
	{	
		memset(bit,0,sizeof(bit));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x++;			
			ans[query(x)]++;
			add(x,1);
		}			
		for(int i=0;i<n;i++)
			printf("%d\n",ans[i]);
	}

	return 0;
}
