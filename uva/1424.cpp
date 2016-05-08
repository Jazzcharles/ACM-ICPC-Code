#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)
int g[200][200],a[220],dp[220][220];
//dp[i][j]:前i个数以数字j结尾最少修改 

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		CLR(g,INF);
		int n,m;
		scanf("%d%d",&n,&m);
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=1;
			g[u][u]=g[v][v]=0;
		}
		int L;
		scanf("%d",&L);
		REP2(i,1,L) scanf("%d",a+i);
		REP2(k,1,n){
			REP2(i,1,n){
				REP2(j,1,n){
					if(g[i][k] && g[k][j])
						g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		CLR(dp,INF);
		REP(i,n) dp[0][i]=0;
		REP2(i,1,L){
			REP2(j,1,n){
				REP2(k,1,n){
					if(g[j][k]<=1){
						dp[i][j]=min(dp[i][j],dp[i-1][k]+((j==a[i])?0:1));
				//		cout<<i<<' '<<j<<' '<<dp[i-1][k]<<' '<<dp[i][j]<<endl;
					}	
				}
			}
		}	
		int ans=INF;
		REP2(i,1,n) ans=min(ans,dp[L][i]); 
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
7 9
1 2
2 3
2 4
2 6
3 4
4 5
5 6
7 4
7 5
9 1 2 2 7 5 5 5 7 4
7 9
1 2
2 3
2 4
2 6
3 4
4 5
5 6
7 4
7 5
9 1 2 2 6 5 5 5 7 4
*/
