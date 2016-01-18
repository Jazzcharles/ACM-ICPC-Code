#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
#define  MP(a,b) make_pair(a,b)
#define  PB(x) push_back(x)
#define  INF 0x3f3f3f3f
const int maxn=1e5+5;
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
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII,VII,greater<PII> >q;
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
	int n,m;
	while(scanf("%d",&n)!=EOF){
		init(n);
		for(int i=0;i<n;i++){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		dijkstra(0,n);
		cout<<dis[n-1]<<endl;
	}
	return 0;
}
