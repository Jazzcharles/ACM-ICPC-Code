#include<iostream>
#include<cstring>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1e5+5;
int bit[maxn];
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
	int n;
	while(~scanf("%d",&n) && n)
	{
		memset(bit,0,sizeof(bit));
		for(int i=1;i<=n;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			add(l,1);
			add(r+1,-1);
		}
		printf("%d",query(1));
		for(int i=2;i<=n;i++){
			printf(" %d",query(i));
		}
		putchar('\n');
	}
	return 0;
}
