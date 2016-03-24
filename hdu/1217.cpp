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
VII G[MAXN]; // G[x] = �� x ��ָ��ĵ㼯, ����������Ϣ
bool vis[MAXN]; // vis[x] = �� x �Ƿ���ʹ�
double dis[MAXN]; // dis[x] = �����㵽�� x ����̾���
int inqueue[MAXN]; // inqueue[x] =�� x ��Ӵ���, ���� n ��Ϊ���ڸ�Ȩ��·
bool Exist; // ���ڸ�Ȩ��·ʱ Exist = 1 ������Ϊ 0
// ��Դ�ͼǰ�ĳ�ʼ��
void init(int n) {
    for (int i = 0; i < n; i++)
    G[i].clear();
    Exist = 0;
}
void add_edge(int u, int v, double w) {
    G[u].push_back(make_pair(v, w));
}
// �����·: (s)>--->...>--->(n)
void SPFA(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(inqueue, 0, sizeof(inqueue));
    memset(dis,0,sizeof(dis));
    dis[s] = 1;
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
             double w = G[x][i].second;
             // �����Ҫ�������·
             if (dis[y] < dis[x] * w) {
                  dis[y] = dis[x] * w;
             //     cout<<y<<' '<<dis[y]<<endl;
                  // ���º�Ľڵ�������ڶ�����.
                  if (!vis[y]) {
                 // ������в���ǡ�����
                    q.push(y);
                    vis[y] = true;
                    // ÿ���������� n-1 ��, ������˵�����ڸ�Ȩ��·
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
