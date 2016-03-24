#include <iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
#define  MP(a,b) make_pair(a,b)
#define  PB(a,b) push_back(a,b)
#define  INF 0x3f3f3f3f
const int maxn=1e5+5;
VII G[maxn];
int vis[maxn],dis[maxn];
void add_edge(int u,int v,int d){
    G[u].push_back(MP(v,d));
}
 
void init(int n){
    for(int i=0;i<n;i++){
        G[i].clear();
    }
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis)); 
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
            int y=G[x][i].first;
            int d=G[x][i].second;
            if(!vis[y] && dis[x]+d < dis[y]){
                dis[y]=dis[x]+d;
                q.push(MP(dis[y],y));
            }
        }
    }
}

 
int main(int argc, char** argv) {
	int n;
	ios::sync_with_stdio(false);
	while(cin>>n && n!=-1){
		init(n);
		map<string,int> m;
		string s,e;
		cin>>s>>e;
		int f=0;
		if(s==e) f=1;
		m[s]=1;m[e]=2;
		int d,j=3;
		for(int i=0;i<n;i++){
			string u,v;
			cin>>u>>v>>d;		
			//cout<<m["xiasha"]<<endl;
			if(!m[u]) {
				m[u]=j++;
			}
			if(!m[v]) {				
				m[v]=j++;
			}
			add_edge(m[u],m[v],d);
			add_edge(m[v],m[u],d);
		}
		dijkstra(1,j);
		if(dis[2]==INF) dis[2]=-1;
		if(f) dis[2]=0;
		printf("%d\n",dis[2]);
	} 
    return 0;
}
