#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
#define  MP(a,b) make_pair(a,b)
#define  PB(a,b) push_back(a,b)
#define  INF 0x3f3f3f3f
const int maxn=1e3+5;
VII G[maxn];
int vis[maxn],dis[maxn];
int a[maxn];
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
int main(){
	int n,s,t;
	while(cin>>n && n)
	{
		init(n);
		cin>>s>>t;
		s--;t--;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]+i<n) add_edge(i,a[i]+i,1);
			if(i-a[i]>=0) add_edge(i,i-a[i],1); 
		}
		dijkstra(s,n);
	//	for(int i=0;i<n;i++) cout<<dis[i]<<endl;
		if(dis[t]==INF) dis[t]=-1;
		cout<<dis[t]<<endl; 
	}
	
	return 0;
}
