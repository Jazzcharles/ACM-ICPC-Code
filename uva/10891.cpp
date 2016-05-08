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

int a[120],dp[200][200],sum[200],sumr[200];
//dp[i][j]:从i到j的最大差值,ans=dp[0][n-1]; 
int main(){
	int n;
	ios::sync_with_stdio(false);
	while(~scanf("%d",&n),n){
		CLR(sum,0);
		CLR(sumr,0);
		CLR(dp,-INF);
		REP2(i,1,n) {
			scanf("%d",&a[i]);	
			sum[i]=sum[i-1]+a[i]; 
		}
		DEP2(i,n,1) sumr[i]=sumr[i+1]+a[i];
		REP2(i,1,n) dp[i][i]=a[i];
		REP2(j,1,n){
			for(int i=j-1;i>=1;i--){
				for(int k=j;k>=i;k--){
					if(k==j) dp[i][j]=max(dp[i][j],sumr[i]-sumr[k+1]);
					else dp[i][j]=max(dp[i][j],max(sum[j]-sum[k]-dp[i][k],sumr[i]-sumr[k+1]-dp[k+1][j]));	
				//	cout<<i<<' '<<j<<' '<<k<<')'<<sumr[i]-sumr[k+1]<<' '<<dp[k+1][j]<<')'<<sum[j]-sum[k]<<' '<<dp[i][k]<<')'<<dp[i][j]<<endl;
				}
			}
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}

/*
3 
4 -10 -20
4
4 -10 -20 7
4
1 2 3 4
0

*/
