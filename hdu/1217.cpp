#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
typedef pair<int,int> PII;
typedef vector<pair<int,double> > VII;
const int MAXN =5000;
const int INF = 0x3F3F3F3F;
VII G[MAXN]; // G[x] = 点 x 所指向的点集, 包含长度信息
bool vis[MAXN]; // vis[x] = 点 x 是否访问过
double dis[MAXN]; // dis[x] = 出发点到点 x 的最短距离
int inqueue[MAXN]; // inqueue[x] =点 x 入队次数, 超过 n 次为存在负权回路
bool Exist; // 存在负权回路时 Exist = 1 不存在为 0
// 针对存图前的初始化
void init(int n) {
    for (int i = 0; i < n; i++)
    G[i].clear();
    Exist = 0;
}
void add_edge(int u, int v, double w) {
    G[u].push_back(make_pair(v, w));
}
// 求最短路: (s)>--->...>--->(n)
void SPFA(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(inqueue, 0, sizeof(inqueue));
    memset(dis,0,sizeof(dis));
    dis[s] = 1;
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
             double w = G[x][i].second;
             // 如果需要更新最短路
             if (dis[y] < dis[x] * w) {
                  dis[y] = dis[x] * w;
             //     cout<<y<<' '<<dis[y]<<endl;
                  // 更新后的节点如果不在队列中.
                  if (!vis[y]) {
                 // 加入队列并标记、计数
                    q.push(y);
                    vis[y] = true;
                    // 每个点最多更新 n-1 次, 超过则说明存在负权回路
                    if (++inqueue[y] >= n) Exist = 1;
                  }
            //  }
          }
          if (Exist) break;
        }
}
}

int main(){
	int n,ca=1;
	while(cin>>n && n){
		init(n);
		map<string,int> m;
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			m[str]=i;
		}
		int q;cin>>q;
		while(q--){
			string u,v;
			double d;
			cin>>u>>d>>v;
			add_edge(m[u],m[v],d);
		}
		int f=0;
		for(int i=0;i<n;i++){
			SPFA(i,n);
			if(dis[i]>1){
				f=1;break;
			}			
		}
		if(f) printf("Case %d: Yes\n",ca++);
		else printf("Case %d: No\n",ca++); 
	//	for(int i=0;i<n;i++) cout<<dis[i]<<' ';cout<<endl;
	}
	return 0;
}
