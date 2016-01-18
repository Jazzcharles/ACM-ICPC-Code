#include <bits/stdc++.h>
using namespace std;
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
typedef pair<int,int> PII;
typedef vector<PII> VII;

const int MAXN=2000;
const int INF=0x3FFFFFFF;

int G[MAXN][MAXN];

int vis[MAXN];
int dis[MAXN];
void dijkstra(int s,int n){
    for(int i = 0;i<n;i++)vis[i] = 0;
    for(int i = 0;i<n;i++)dis[i] = (i == s ? 0 : INF);
    for(int i = 0;i<n;i++){
        int x,minn = INF;
        for(int j = 0;j<n;j++){
            if(!vis[j]&&dis[j]<=minn){
                x = j;
                minn = dis[j];
            }
        }
        vis[x] = 1;
        for(int j=0;j<n;j++){
            int y = j;
            dis[y] = min(dis[y], dis[x] + G[x][y]);
        }
    }
}


int main(int argc, char** argv) {
	int n,ca=1;
	while(cin>>n){
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
		  {
		    int x;
		  	scanf("%d",&x);
		  	if(x!=-1)
		  	   G[i][j]=x;
		  	else
		  	   G[i][j]=INF;
		}
		int s,t;
		scanf("%d%d",&s,&t);
		dijkstra(s-1,n);
		printf("Case %d\n%d\n",ca++,dis[t-1]);
	}
	return 0;
}
