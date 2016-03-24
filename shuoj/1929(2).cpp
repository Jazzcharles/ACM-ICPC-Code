#include<bits/stdc++.h>
using namespace std;
#define MP(a,b) make_pair(a,b)
typedef pair<int,int> PII;
typedef vector<PII> VII; 
const int MAXN =150;
const int INF = 0x3F3F3F3F;
VII G[MAXN]; // G[x] = 点 x 所指向的点集, 包含长度信息
bool vis[MAXN]; // vis[x] = 点 x 是否访问过
int dis[MAXN]; // dis[x] = 出发点到点 x 的最短距离
int inqueue[MAXN]; // inqueue[x] =点 x 入队次数, 超过 n 次为存在负权回路
bool Exist; // 存在负权回路时 Exist = 1 不存在为 0
// 针对存图前的初始化
void init(int n) {
	for(int i = 0; i < MAXN; i++) G[i].clear();
	for(int i=0;i<n;i++) G[0].push_back(MP(i+1,0)); 
}
void add_edge(int u, int v, int w) {
    G[u].push_back(make_pair(v, w));
}
// 求最短路: (s)>--->...>--->(n)
void SPFA(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
   // 待优化的节点入队
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = false; // 点 x 此时不在队列中
        // 遍历所有 x 指向的点
        for (int i = 0; i < G[x].size(); i++) {
             int y = G[x][i].first;
             int w = G[x][i].second;
             // 如果需要更新最短路
             if (dis[y] < dis[x] + w) {
                  dis[y] = dis[x] + w;
                  // 更新后的节点如果不在队列中
                  if (!vis[y]) {
                 // 加入队列并标记、计数
                    q.push(y);
                    vis[y] = true;
                    // 每个点最多更新 n-1 次, 超过则说明存在负权回路
                  }
              }
          }
        }
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{   
		int n,p,q;
		scanf("%d%d%d",&n,&p,&q); 
		init(n);
		while(p--){
			int u,d;
			scanf("%d%d",&u,&d);
			add_edge(0,u,d);
		}
		while(q--){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(v,u,d);
		}
		SPFA(0,n);
		for(int i=0;i<=n;i++) cout<<dis[i]<<endl;
		printf("%d\n",dis[1]);
	}
	
	return 0;
}
