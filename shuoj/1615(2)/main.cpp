#include <bits/stdc++.h>
using namespace std;
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
typedef  pair<int,int> PII;
typedef  vector<PII> VII;

const int MAXN=200;
vector<PII> G[MAXN];
void add_edge(int u,int v,int d){
    G[u].PB(MP(v,d));
}
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
int vis[MAXN];
int dis[MAXN];
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII,VII,greater<PII> >q;
    vis[s] = 0;
    q.push(MP(dis[s],s));
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])continue;
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
	int n,ca=1;
	while(cin>>n){
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
		  {
		    int x;
		  	scanf("%d",&x);
		  	if(x!=-1)
		  	   add_edge(i,j,x);
		  	else
		  	   add_edge(i,j,INF);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		dijkstra(s-1,n);
		printf("Case %d\n%d\n",ca++,dis[t-1]);
	}
	return 0;
}
