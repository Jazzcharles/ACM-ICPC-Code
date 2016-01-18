#include <bits/stdc++.h>
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a,b)
#define INF 0x3FFFFFFF
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef pair<pair<int,int>,int> PIII;
typedef vector<PIII> VIII;             //用vector存图 

const int MAXN = 100010;
VIII G[MAXN];
void add_edge(int u,int v,int d,int w){
    G[u].PB(MP(MP(v,d),w));          //表示点u到点v的预估距离为d,实际距离为w 
}
void init(int n){			//初始化清零 
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
int vis[MAXN];		//记录访问过的边 
int dis[MAXN];		//记录最短路 
int res[MAXN];		//记录最长路 
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);	//每次求最短，初始值设为最大 
    for(int i=0;i<n;i++)res[i] = (i == s ? 0 : -1);		//每次求最长，初始值设为负 
    //优先队列优化，dis[s]在前保证每次距离最小的点在顶,优先更新最短距离的点，充分利用优先子结构的性质。 
	priority_queue<PII,VII,greater<PII> >q;			 
    q.push(MP(dis[s],s));      
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x]) continue;	//访问过的点不再访问 
        vis[x] = 1;				//取出起点x对应的所有终点y，分别更新预估距离d和实际距离w
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first.first;	 
            int d = G[x][i].first.second;
            int w = G[x][i].second;
            if(!vis[y] && dis[x] + d < dis[y]){		//若当前最短距离能被更新，同时更新dis,res数组 
                dis[y] = dis[x] + d;
                res[y] = res[x] + w;
//              res[y] = max(res[y],res[x]+w);
 //             cout<<res[y]<<endl;
                q.push(MP(dis[y],y));
            }
            if(!vis[y] && dis[x]+d==dis[y]){     //只有出现相同最短路径时，才取较长的实际距离更新res数组 
            	res[y]=max(res[y],res[x]+w);
			}
        }
    }
}
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,s,t;
		scanf("%d%d%d%d",&n,&m,&s,&t);
		init(n);
		while(m--){
			int u,v,d,b;
			scanf("%d%d%d%d",&u,&v,&d,&b);
			u--;v--;			//下标从0开始 
			add_edge(u,v,d,b);
			add_edge(v,u,d,b);
		}
		dijkstra(s-1,n);
		cout<<dis[t-1]<<' '<<res[t-1]<<endl;
	}
	return 0;
}
