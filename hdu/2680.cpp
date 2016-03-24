#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define INF 0x3f3f3f3f
const int MAXN = 5000;	
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
VII G[MAXN];		
int vis[MAXN];		
int dis[MAXN];		
void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
}

void add_edge(int u, int v, int w) {
	G[u].push_back(make_pair(w, v));
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
			int w = G[x][i].first;
			
			if (!vis[y] && dis[y] > dis[x] + w) {
				dis[y] = dis[x] + w;
				Q.push(make_pair(dis[y], y));
			}
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false); 
	int n,m,t;
	while(cin>>n>>m>>t)
	{
		init(n+1);
		while(m--){
			int u,v,d;
			cin>>u>>v>>d;
			add_edge(u,v,d);
		} 
		int q;
		cin>>q;
		while(q--){
			int v;
			cin>>v;
			add_edge(0,v,0);
		}
		Dijkstra(0,n+1);
		//for(int i=0;i<=n;i++) cout<<dis[i]<<' ';cout<<endl;
		if(dis[t]==INF) cout<<-1<<endl;
		else cout<<dis[t]<<endl;
	}
	
	return 0;
}
