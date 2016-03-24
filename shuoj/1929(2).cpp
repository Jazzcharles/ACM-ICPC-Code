#include<bits/stdc++.h>
using namespace std;
#define MP(a,b) make_pair(a,b)
typedef pair<int,int> PII;
typedef vector<PII> VII; 
const int MAXN =150;
const int INF = 0x3F3F3F3F;
VII G[MAXN]; // G[x] = �� x ��ָ��ĵ㼯, ����������Ϣ
bool vis[MAXN]; // vis[x] = �� x �Ƿ���ʹ�
int dis[MAXN]; // dis[x] = �����㵽�� x ����̾���
int inqueue[MAXN]; // inqueue[x] =�� x ��Ӵ���, ���� n ��Ϊ���ڸ�Ȩ��·
bool Exist; // ���ڸ�Ȩ��·ʱ Exist = 1 ������Ϊ 0
// ��Դ�ͼǰ�ĳ�ʼ��
void init(int n) {
	for(int i = 0; i < MAXN; i++) G[i].clear();
	for(int i=0;i<n;i++) G[0].push_back(MP(i+1,0)); 
}
void add_edge(int u, int v, int w) {
    G[u].push_back(make_pair(v, w));
}
// �����·: (s)>--->...>--->(n)
void SPFA(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
   // ���Ż��Ľڵ����
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = false; // �� x ��ʱ���ڶ�����
        // �������� x ָ��ĵ�
        for (int i = 0; i < G[x].size(); i++) {
             int y = G[x][i].first;
             int w = G[x][i].second;
             // �����Ҫ�������·
             if (dis[y] < dis[x] + w) {
                  dis[y] = dis[x] + w;
                  // ���º�Ľڵ�������ڶ�����
                  if (!vis[y]) {
                 // ������в���ǡ�����
                    q.push(y);
                    vis[y] = true;
                    // ÿ���������� n-1 ��, ������˵�����ڸ�Ȩ��·
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
