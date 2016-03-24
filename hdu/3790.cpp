#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
typedef vector<PII> VII;
typedef vector<PIII> VIII;
#define  MP(a,b) make_pair(a,b)
#define  PB(a,b) push_back(a,b)
#define  INF 0x3f3f3f3f
const int maxn=1e3+5;
VIII G[maxn];
int vis[maxn],dis[maxn],cost[maxn];
void add_edge(int u,int v,int d,int w){
    G[u].push_back(MP(MP(v,d),w));
}
 
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
 
void dijkstra(int s,int n){
    priority_queue<PII,VII,greater<PII> >q;
    for(int i=0;i<n;i++){
        dis[i]=(i==s?0:INF);
		vis[i]=0;
    }
    q.push(MP(dis[s],s));
    while(!q.empty()){
        PII p=q.top();q.pop();  
        int x=p.second;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0;i<G[x].size();i++){
            int y=G[x][i].first.first;
            int d=G[x][i].first.second;
            int w=G[x][i].second;
            if(!vis[y] && dis[x]+d < dis[y]){
                dis[y]=dis[x]+d;
                cost[y]=cost[x]+w;
                q.push(MP(dis[y],y));
            }
            if(!vis[y] && dis[x]+d == dis[y]){
            	if(cost[y]>cost[x]+w){
            		dis[y]=dis[x]+d;
            		cost[y]=cost[x]+w;
					q.push(MP(dis[y],y));
				}
			}
        }
    }
}
 
int main(int argc, char** argv) {
   	int n,m;
   	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		if(!m && !n) break;
		memset(dis,0,sizeof(dis));
		memset(cost,0,sizeof(cost));
		init(n);
	   	while(m--){
			int u,v,d,w;
			cin>>u>>v>>d>>w;
			u--;v--;
			add_edge(u,v,d,w);
			add_edge(v,u,d,w);
	   	}
	   	int s,t;
	   	cin>>s>>t;
	   	s--;t--;
	   	dijkstra(s,n);
	   	//for(int i=0;i<n;i++) cout<<dis[i]<<endl; 
	   	cout<<dis[t]<<' '<<cost[t]<<endl;		
	}

    return 0;
}
