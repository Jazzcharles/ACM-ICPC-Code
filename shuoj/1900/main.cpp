#include <bits/stdc++.h>
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a,b)
#define INF 0x3FFFFFFF
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef pair<pair<int,int>,int> PIII;
typedef vector<PIII> VIII;             //��vector��ͼ 

const int MAXN = 100010;
VIII G[MAXN];
void add_edge(int u,int v,int d,int w){
    G[u].PB(MP(MP(v,d),w));          //��ʾ��u����v��Ԥ������Ϊd,ʵ�ʾ���Ϊw 
}
void init(int n){			//��ʼ������ 
    for(int i=0;i<n;i++){
        G[i].clear();
    }
}
int vis[MAXN];		//��¼���ʹ��ı� 
int dis[MAXN];		//��¼���· 
int res[MAXN];		//��¼�· 
void dijkstra(int s,int n){
    for(int i=0;i<n;i++)vis[i] = 0;
    for(int i=0;i<n;i++)dis[i] = (i == s ? 0 : INF);	//ÿ������̣���ʼֵ��Ϊ��� 
    for(int i=0;i<n;i++)res[i] = (i == s ? 0 : -1);		//ÿ���������ʼֵ��Ϊ�� 
    //���ȶ����Ż���dis[s]��ǰ��֤ÿ�ξ�����С�ĵ��ڶ�,���ȸ�����̾���ĵ㣬������������ӽṹ�����ʡ� 
	priority_queue<PII,VII,greater<PII> >q;			 
    q.push(MP(dis[s],s));      
    while(!q.empty()){
        PII p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x]) continue;	//���ʹ��ĵ㲻�ٷ��� 
        vis[x] = 1;				//ȡ�����x��Ӧ�������յ�y���ֱ����Ԥ������d��ʵ�ʾ���w
        for(int i=0;i<G[x].size();i++){
            int y = G[x][i].first.first;	 
            int d = G[x][i].first.second;
            int w = G[x][i].second;
            if(!vis[y] && dis[x] + d < dis[y]){		//����ǰ��̾����ܱ����£�ͬʱ����dis,res���� 
                dis[y] = dis[x] + d;
                res[y] = res[x] + w;
//              res[y] = max(res[y],res[x]+w);
 //             cout<<res[y]<<endl;
                q.push(MP(dis[y],y));
            }
            if(!vis[y] && dis[x]+d==dis[y]){     //ֻ�г�����ͬ���·��ʱ����ȡ�ϳ���ʵ�ʾ������res���� 
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
			u--;v--;			//�±��0��ʼ 
			add_edge(u,v,d,b);
			add_edge(v,u,d,b);
		}
		dijkstra(s-1,n);
		cout<<dis[t-1]<<' '<<res[t-1]<<endl;
	}
	return 0;
}
