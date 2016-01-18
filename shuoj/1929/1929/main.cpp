#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

const int MAXN = 2000;
int Ans[MAXN],check[MAXN][MAXN]; // 存放拓扑排序结果
vector<int> G[MAXN]; // 邻接表
int deg[MAXN]; // 记录点的入度
//map<PII, bool> S; // 用于判断重边
// 存图前初始化
void init(int n) {
    for (int i = 0; i < n; i++)G[i].clear();
    memset(deg, 0, sizeof(deg));
    memset(Ans, 0, sizeof(Ans));
    memset(check,INF,sizeof(check));
}
// 添加 U->V 的有向边
void add_edge(int u, int v,int d) {
// 判断重边
//    if (S[make_pair(u, v)]) return;
    check[u][v]=min(check[u][v],d);
    G[u].push_back(v);
    S[make_pair(u, v)] = 1;
    deg[v]++;
}
// 直接调用, 如需判断有环, 0 有 1 没有
bool Toposort(int n) {
    int tot = 0;
    queue<int> que;
// 入度为 0 的点入队
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0) que.push(i);
    while (!que.empty()) {
            int v = que.front(); que.pop();
            Ans[tot++] = v;
// 更新与该点相关的点的入度
            for (int i = 0; i < G[v].size(); ++i) {
                int t = G[v][i];
// 若发现新的入度为 0 的点, 入队
                if (--deg[t] == 0) que.push(t);
            }
        }
    if (tot < n) return false;
    return true;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p,q,cnt=0;
		scanf("%d%d%d",&n,&p,&q);
		init(n);
		while(p--){
			int v,d;
			cnt++;
			scanf("%d%d",&v,&d);
			Map[0][v]=min(Map[0][v],d);
			add_edge(0,v,Map[0][v]);
		}
		if(!cnt){
            while(q--){
                int u,v,d;
                scanf("%d%d%d",&u,&v,&d);
                Map[v][u]=min(Map[v][u],d);
                add_edge(v,u,Map[v][u]);
                add_edge(0,v,0);
            }
		}
		else{
           while(q--){
                int u,v,d;
                scanf("%d%d%d",&u,&v,&d);
                Map[v][u]=min(Map[v][u],d);
                add_edge(v,u,Map[v][u]);
           }
		}
		Dijkstra(0,n+1);
		if(dis[1]==INF) dis[1]=0;
		cout<<dis[1]<<endl;
	}
	return 0;
}
