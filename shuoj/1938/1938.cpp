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
#define INF 0x3FFFFFFF
#define EPS 1e-8
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define lowbit(i) (i&(-i))
#define IT iterator
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define pi 3.1415927
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn=1e5+5;
const int mod=1e9+7;
const int B=1031;
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

ll dp[1005][1005];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);		
	dp[0][0]=1;
	    for(int j=0;j<=1000;j++){
			 for(int i=j;i<=1000;i++){
			     if(j==1) dp[i][j]=i;
			     else if(j==0) dp[i][j]=1;	
				 else dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod)%mod;
	    }	
    }
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%lld\n",dp[n][m]);
	}
	
	
	
	
	return 0;
}
