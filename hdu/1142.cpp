#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI; 
typedef vector<PII> VII; 
typedef long long ll;
const int MAXN = 5000;	
VII G[MAXN];		
int vis[MAXN],dp[MAXN];		
ll dis[MAXN],cnt;	
VI fa[MAXN];
	
void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
	for (int i = 0; i < n; i++)
		fa[i].clear();
	memset(dp,0,sizeof(dp));
}

void add_edge(int u, int v, ll w) {
	G[u].push_back(make_pair(w, v));
}

int dfs(int cur){
	if(dp[cur]) return dp[cur];
	if(cur==1) {
		return 1;
	}
	for(int i=0;i<G[cur].size();i++){
		int v=G[cur][i].second;
		if(dis[v]<dis[cur])
		{
	//		cout<<cur<<' '<<v<<' '<<dp[cur]<<endl;
			dp[cur]+=dfs(v);
		}	
	}
	return dp[cur];
}
void Dijkstra(int s, int n) {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) dis[i] = INF;
	dis[s] = 0;
	priority_queue<PII, VII, greater<PII> > Q;
	Q.push(make_pair(dis[s], s));	
	while (!Q.empty()) {
		PII t = Q.top();	
		int x = t.second;	
		Q.pop();			
		if (vis[x]) continue;
		vis[x] = 1;
		
		for (int i = 0; i < G[x].size(); i++) {
			int y = G[x][i].second;	
			ll w = G[x][i].first;

			if (!vis[y] && dis[y] > dis[x] + w) {	
				dis[y] = dis[x] + w;
				Q.push(make_pair(dis[y], y));
			}
		//	cout<<y<<' '<<dis[y]<<endl;
		
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d",&n),n)
	{
		scanf("%d",&m);
		cnt=0;
		init(n);
		while(m--){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			u--;v--;
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		Dijkstra(1,n);	
	//	cout<<666666666<<endl;
		dfs(0);	
	//	for(int i=0;i<n;i++) cout<<dp[i]<<' ';cout<<endl; 
		printf("%d\n",dp[0]);
	}
	
	return 0;
} 
/*
4 5
1 2 6
1 3 2
1 4 4
2 3 3
2 4 1
*/
