#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;

const int maxn=1e3+5;
VII G[maxn];
int vis[maxn],dis[maxn];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
void dijkstra(int s,int n){
	priority_queue<PII,VII,greater<PII> >q;
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    q.push(MP(dis[s],s));
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
        vis[x] = 1;
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first;
            int d = G[x][i].second;
            if(!vis[y]&&dis[x] + d < dis[y]){
                dis[y] = dis[x] + d;
                q.push(MP(dis[y],y));
            }
        }
    }
}

int main(int argc, char** argv) {
	int n,m,k,ca=1;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init(n);
		int s,t,u,v,d;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		cout<<"Case "<<ca++<<endl;
		while(k--){
			scanf("%d%d",&s,&t);
			dijkstra(s,n);	
			cout<<(dis[t]==INF?-1:dis[t])<<endl;
		}

	}
	return 0;
}
