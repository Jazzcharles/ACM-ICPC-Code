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

int a[200],dp[200][200],sum[200];
//dp[i][j]:前i个分成j份的最小值 
//dp[i][j]=min(dp[p][j-1]+
int cmp(int a,int b){
	return a>b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,s=0;
		cin>>n>>k;
		REP2(i,1,n) {
			cin>>a[i];	
			s+=a[i];
		}
		CLR(dp,INF);
		CLR(sum,0);
		sort(a+1,a+1+n,cmp);
		REP2(i,1,n) sum[i]=sum[i-1]+a[i];
		//REP2(i,1,n) cout<<sum[i]<<' ';cout<<endl;
		REP2(i,1,n) dp[i][1]=i*sum[i];
		REP2(i,1,n){
			for(int j=2;j<=k && j<=i;j++){
				//dp[i][j]=min(dp[i][j],dp[i-1][j]+sum[i-1]+i*a[i],dp[i-1][j-1]+a[i]);	
				for(int p=1;p<=i;p++){
					dp[i][j]=min(dp[i][j],dp[p][j-1]+i*(sum[i]-sum[p]));
		//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				}
			} 
		}
		printf("%.4f\n",dp[n][k]*1.0/s);
	}
	
	
	
	return 0;
}
/*
2
5 2
30 5 10 30 25
5 5
30 5 10 30 25

30 30 25 10 5
*/
