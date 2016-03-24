#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
const int MAXN =20005;
int Ans[MAXN],tot,res; // �������������
vector<int> G[MAXN]; // ���ͼ��Ϣ
int deg[MAXN]; // ��ŵ������Ϣ
map<PII,int> mp;
void init(int n) {
 	for(int i=0;i<n;i++) G[i].clear();
 	mp.clear();
 	memset(deg, 0, sizeof(deg));
 	memset(Ans, 0, sizeof(Ans));
}
// ��� U->V �������
void add_edge(int u, int v) {
 	if (mp[MP(u,v)]) return;
 	G[u].push_back(v);
 	mp[MP(u,v)]=1; 
 	deg[v]++;
}
// ֱ�ӵ���, �����ж��л�, 0 �� 1 û��
bool Toposort(int n) {
 	//queue<int> que;
 	 queue<PII>que;
	 for (int i = 0; i < n; ++i)
 		if (deg[i] == 0) que.push(MP(i,888));
 		while (!que.empty()) {
 			int u = que.front().first; 
			int d = que.front().second;
			que.pop();
 			res+=d;
			Ans[tot++] = u+1;
	 		for (int i = 0; i < G[u].size() ; ++i){
	 			int v=G[u][i];
 				if (--deg[v] == 0) que.push(MP(v,d+1));		
			 }
 		
	 }
 	if (tot < n) return false;
 	return true;
}

int main(){
	int n,m;
	while(cin>>n>>m)	
	{
		init(n);
		tot=0;
		res=0;
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			u--;v--;
			add_edge(v,u);
		} 
		int f=Toposort(n);
		if(!f) cout<<-1<<endl;
		else cout<<res<<endl; 
	}
	return 0;
} 
