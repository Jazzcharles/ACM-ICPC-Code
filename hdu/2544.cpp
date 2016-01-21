#include <iostream>
#include<queue>
#define MP(a,b) make_pair(a,b) 
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int maxn=1e5;

VII G[maxn];
int n,m,dis[maxn],vis[maxn];
void init(int n){
	for(int i=0;i<n;i++)
		G[i].clear();
}

void add_edge(int u,int v,int d){
	G[u].push_back(MP(v,d));
}

void dijkstra(int s,int n){
	for(int i=0;i<n;i++) dis[i]=(i==s?0:INF);
	for(int i=0;i<n;i++) vis[i]=0;
	priority_queue<PII,VII,greater<PII> >q;
	q.push(MP(dis[s],s));
	while(!q.empty())	
	{
		PII p=q.top();q.pop();
		int x=p.second;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<G[x].size();i++){
			int y=G[x][i].first;
			int w=G[x][i].second;
			if(!vis[y] && dis[y]> dis[x]+w){
				dis[y]=dis[x]+w;
				q.push(MP(dis[y],y));
			}
		}
	}
}
int main(int argc, char** argv) {
	while(~scanf("%d%d",&n,&m)){
		if(!n && !m) break;
		init(n);
		for(int i=1;i<=m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--;y--;
			add_edge(x,y,z);
			add_edge(y,x,z);
		}
		dijkstra(0,n);
		cout<<dis[n-1]<<endl;
	}
	
	
	
	
	return 0;
}
