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
const int maxn=1e3+5;
char a[maxn];
int dp[maxn];
//dp[j]:从头到j最少回文的组数 

bool rev(int i,int j){
	for(int l=i,r=j;l<r;l++,r--){
		if(a[l]!=a[r]) return 0;
	}
	return 1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",a+1);
		CLR(dp,0);
		int n=strlen(a+1);
		REP2(i,1,n){
			dp[i]=i;	
			DEP2(j,i,1){
				if(rev(j,i)){
					dp[i]=min(dp[i],dp[j-1]+1);
				}
			}
		}
	//	REP2(i,1,n) cout<<dp[i]<<' ';cout<<endl;
		printf("%d\n",dp[n]);
	}

	return 0;
}
/*
5
aaadbccb

abbababa
abababba
racecar
fastcar


*/
