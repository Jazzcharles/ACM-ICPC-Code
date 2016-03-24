#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
#include<vector>
#include<cstring>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
const int MAXN =105;
int Ans[MAXN]; // 存放拓扑排序结果
vector<PII> G[MAXN]; // 存放图信息
int deg[MAXN]; // 存放点入度信息
int mp[MAXN][MAXN];
void init() {
 	memset(deg, 0, sizeof(deg));
 	memset(Ans, 0, sizeof(Ans));
 	for(int i=0;i<MAXN;i++) G[i].clear();
 	for(int i=0;i<MAXN;i++) G[0].push_back(MP(i+1,0));
}
// 添加 U->V 的有向边
void add_edge(int u, int v,int d) {
	G[u].push_back(MP(v,d));
	deg[v]++;
}
// 直接调用, 如需判断有环, 0 有 1 没有
bool Toposort(int n) {
 	queue<int> q;
	for(int i=0;i<n;i++){
		if(!deg[i]) q.push(i);  
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].first;
			int d=G[u][i].second;
			if(deg[v]) deg[v]--;
		//	cout<<u<<' '<<v<<' '<<deg[v]<<endl; 
			if(Ans[v]<Ans[u]+d){
				Ans[v]=Ans[u]+d;
		//		cout<<v<<' '<<deg[v]<<endl;
				if(!deg[v]) q.push(v);		
			}
		}
	//	for(int i=0;i<=n;i++) cout<<Ans[i]<<' ';cout<<endl;
	}
}


int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) 
	{
		init();
		int n,p,q;
		cin>>n>>p>>q;
		while(p--){
			int x,num;
			cin>>x>>num;
			add_edge(0,x,num);
		} 
		while(q--){
			int u,v,d;
			cin>>u>>v>>d;
			add_edge(v,u,d);
		}
	//	for(int i=0;i<=n;i++) cout<<G[i].size()<<' ';cout<<endl;
		Toposort(n);
	//	for(int i=0;i<=n;i++) cout<<Ans[i]<<endl;
		cout<<Ans[1]<<endl;
	}
	return 0;
} 
/*
5
4 4 4
1 100
2 200
3 300
4 400
2 4 500
1 2 100
2 3 500
2 3 300

*/
