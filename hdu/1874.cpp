#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
#define  MP(a,b) make_pair(a,b)
#define  PB(a,b) push_back(a,b)
#define  INF 0x3f3f3f3f
const int maxn=1e3+5;
VII G[maxn];
int vis[maxn],dis[maxn];
void add_edge(int u,int v,int d){
    G[u].push_back(MP(v,d));
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
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        init(n);
        int s,t,u,v,d;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&d);
            add_edge(u,v,d);
            add_edge(v,u,d);
        }
        scanf("%d%d",&s,&t);
        dijkstra(s,n);  
        cout<<(dis[t]==INF?-1:dis[t])<<endl;
    }
    return 0;
}
