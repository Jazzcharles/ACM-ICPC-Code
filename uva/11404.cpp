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
const int MAXN=1050;
struct node{
	string s;
}ans[MAXN][MAXN];
int dp[MAXN][MAXN],mark[MAXN][MAXN];
char a[MAXN],b[MAXN];
int main(){
	ios::sync_with_stdio(false);
	while(gets(a+1))
	{
		CLR(dp,0);CLR(mark,0);
		int n=strlen(a+1);
		for(int i=1;i<=n;i++) b[i]=a[n-i+1];	
		//puts(a+1);
		//puts(b+1);
		REP2(i,1,n){
			REP2(j,1,n){
				if(a[i]==b[j]){
						dp[i][j]=dp[i-1][j-1]+1;
						ans[i][j].s=ans[i-1][j-1].s+a[i];
						mark[i][j]=1;
				}
				else{
					if(dp[i-1][j]>dp[i][j-1]){
						dp[i][j]=dp[i-1][j];
						mark[i][j]=2;
						ans[i][j].s=ans[i-1][j].s;
					}
					else if(dp[i][j-1]>dp[i-1][j]){
						dp[i][j]=dp[i][j-1];
						mark[i][j]=3;
						ans[i][j].s=ans[i][j-1].s;
					}
					else{
						dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
						ans[i][j].s=min(ans[i][j-1].s,ans[i-1][j].s);
					}
				}
			//	cout<<ans[i][j].s<<endl;
			}
		//	cout<<endl;
		}
		string res=ans[n][n].s;
		int len=dp[n][n];
		//cout<<res<<endl;
		if(len%2){
			REP(i,len/2) cout<<res[i];
			DEP2(i,len/2,0) cout<<res[i];
		}
		else{
			REP(i,len/2) cout<<res[i];
			DEP2(i,len/2-1,0) cout<<res[i];
		}
		cout<<endl;
	}	
	return 0;
}
/*
aabbaabb
computer
abzla
samhita
kfclbckibbibjccbej
*/
