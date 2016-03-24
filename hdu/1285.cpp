#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN =1005;
int Ans[MAXN],tot; // �������������
int G[MAXN][MAXN]; // ���ͼ��Ϣ
int deg[MAXN]; // ��ŵ������Ϣ
void init() {
 	memset(G, 0, sizeof(G));
 	memset(deg, 0, sizeof(deg));
 	memset(Ans, 0, sizeof(Ans));
}
// ��� U->V �������
void add_edge(int u, int v) {
 	if (G[u][v]) return;
 	G[u][v] = 1;
 	deg[v]++;
}
// ֱ�ӵ���, �����ж��л�, 0 �� 1 û��
bool Toposort(int n) {
 	//queue<int> que;
 	priority_queue<int,vector<int>,greater<int> >que;
	 for (int i = 0; i < n; ++i)
 		if (deg[i] == 0) que.push(i);
 		while (!que.empty()) {
 			int v = que.top(); que.pop();
 			Ans[tot++] = v+1;
 			for (int i = 0; i < n ; ++i)
 				if (G[v][i] == 1)
 				if (--deg[i] == 0) que.push(i);
 	}
 	if (tot < n) return false;
 	return true;
}

int main(){
	int n,m;
	while(cin>>n>>m)	
	{
		init();
		tot=0;
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			u--;v--;
			add_edge(u,v);
		} 
		//for(int i=0;i<n;i++) cout<<deg[i]<<endl;
		Toposort(n);
		cout<<Ans[0];
		for(int i=1;i<n;i++){
			cout<<' '<<Ans[i]; 
		}
		cout<<endl;
	}
	return 0;
} 
