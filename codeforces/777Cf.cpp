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
const int maxn=1e5+500;


int dp[maxn];//dp[k]:到第k行为止的最长的距离 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[n][m],b[n][m];
	for(int i = 0 ;i < n ;i++){
		for(int j = 0; j<m ; j++){
			scanf("%d",&a[i][j]);
		}
	}
	dp[0]=1;
	for(int j=0;j<m;j++) b[0][j]=1;
	for(int j = 0; j < m ; j++){
		for(int i = 1; i < n; i++){
			if(a[i][j]>=a[i-1][j]){
				b[i][j]=b[i-1][j]+1;
			}
			else b[i][j]=1;
			dp[i]=max(dp[i],b[i][j]);
		}
	}	
	
	//for(int i = 0; i < n;i++) cout<<dp[i]<<' ';cout<<endl;
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l--;r--;
		if(dp[r]>=(r-l+1)) printf("Yes\n");
		else printf("No\n");
	}

	
	
	
	return 0;
}
/*
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
*/
