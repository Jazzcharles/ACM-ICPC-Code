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
const int INF = 0x3FFFFFFF;

VII G[MAXN];		
int vis[MAXN];		
int dis[MAXN];		
void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
}

void add_edge(int u, int v, int w) {
	G[u].push_back(make_pair(w, v));
}

void Dijkstra(int s, int n) {

	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) dis[i] = INF;
	dis[s] = 0;

	priority_queue<PII, VII, greater<PII> > Q;
	Q.push(make_pair(dis[s], s));	
	while (!Q.empty()) {
		PII t = Q.top();	
		int x = t.second;	
		Q.pop();			
		if (vis[x]) continue;
		vis[x] = 1;
		
		for (int i = 0; i < G[x].size(); i++) {
			int y = G[x][i].second;	
			int w = G[x][i].first;
			
			if (!vis[y] && dis[y] > dis[x] + w) {
				dis[y] = dis[x] + w;
				Q.push(make_pair(dis[y], y));
			}
		}
		cout<<123<<endl; 
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
			int v,d;
			scanf("%d%d%d",&v,&d);
			add_edge(0,v,d);
		}
		while(q--){
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(v,u,d);
		}
		Dijkstra(0,n);
		cout<<dis[1]<<endl;
	}
	return 0;
} 
