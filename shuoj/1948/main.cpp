#include <bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn= 1e5+5;
const int INF = 0x3F3F3F3F;
ll dis[maxn];
int n;
vector<PII> G[maxn];

void dfs(int cur,int par){		
	for(int i=0;i<G[cur].size();i++){
		int v=G[cur][i].first;
		if(v==par) continue;
		int d=G[cur][i].second;
		if(d){
			dis[v]=dis[cur]^d;
	//		cout<<cur<<' '<<v<<' '<<dis[v]<<endl;
			dfs(v,cur);
		}	
	}
}

int main(int argc, char** argv) {
	int t,ca=1;
	scanf("%d",&t);
	while(t--){
		memset(dis,0,sizeof(dis));
		memset(G,0,sizeof(G));
		int m,s=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n-1;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
//			G[min(u,v)].push_back(MP(max(u,v),d));
			G[u].push_back(MP(v,d));
			G[v].push_back(MP(u,d));
		}
		dfs(1,1);
		printf("Case %d:\n",ca++);
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%lld\n",dis[u]^dis[v]);
		}
	}
	return 0;
}
