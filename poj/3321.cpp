#include <bits/stdc++.h>
using namespace std;
#define lowbit(i) (i&(-i))
const int maxn=1e5+5;

int bit[maxn],a[maxn],s[maxn],t[maxn],count;
vector<int>G[maxn];
void add(int i,int x){
	while(i<=maxn){
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int query(int i){
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=lowbit(i);
	}
}

void dfs(int x){
	s[x]=++cnt;
	for(int i=0;i<G[x].size();i++){
		dfs(G[x][i]);
	}
	t[x]=++cnt;
}
int main(int argc, char** argv) {
	int m,n;
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);			
	}
	dfs(1);
	scanf("%d",&m);
	getchar();
	char q;int x;
	while(m--){
		scanf("%c%d",&q,&x); 
		if(q=='C'){
			add(x,1);
		}
		if(q=='Q'){
			
	}

	return 0;
}
