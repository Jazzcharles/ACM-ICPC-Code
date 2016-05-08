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

char a[200][200];
ll num[200],cnt[1<<17],dp[1<<17];

int main(){
	int n,t,ca=1;		
	string str;
	cin>>t;
	while(t--){
		int s=0;
		cin>>n;
		cin>>str;
		REP(i,str.length()) if(str[i]=='1') s|=(1<<i);
		//cout<<s<<endl;
		CLR(num,0);
		REP(i,n){
			scanf("%s",a[i]);			
			REP(j,a[i][j])
				if(a[i][j]=='1') num[i]|=(1<<j);
		}		
	//	REP(i,n) cout<<num[i]<<' ';cout<<endl; 
		CLR(cnt,0);
		REP(i,(1<<n)) cnt[i]=s;
		REP2(i,1,(1<<n)-1){
			REP(j,n){
				if(i&(1<<j)) cnt[i]|=num[j];
			}
		} 		
		CLR(dp,0);
		dp[0]=1;
		REP2(i,1,(1<<n)-1){
			REP(j,n){
				if(((1<<j))&(cnt[i^(1<<j)])){
					dp[i]+=dp[i^(1<<j)];
		//			cout<<i<<' '<<j<<' '<<dp[i]<<' '<<dp[i^(1<<j)]<<endl;					
				} 

			}
		} 
//		REP(i,(1<<n)) cout<<dp[i]<<' ';cout<<endl;
		printf("Case %d: %lld\n",ca++,dp[(1<<n)-1]);
	}
	return 0;
}
/*
3
1
1
1
2
11
01
10
3
110
011
100
000
*/
