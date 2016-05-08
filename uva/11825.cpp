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
int dp[1<<16],sum[1<<16],p[1<<16];
//sum[i]:和i相邻接的电脑状态
//p[i]:i状态下的所有关联电脑情况 
//dp[i]:关闭i状态的电脑情况下最多瘫痪服务器个数 
int main(){
	int ca=1,n;
	while(~scanf("%d",&n),n){
		CLR(dp,0);CLR(p,0);CLR(sum,0);
		REP(i,n){
			int q;
			scanf("%d",&q);
			sum[i]|=(1<<i);
			while(q--){  
				int v;
				scanf("%d",&v);
				sum[i]|=(1<<v);
			}
		}
	//	REP(i,n) cout<<sum[i]<<' ';cout<<endl;
		REP(i,(1<<n)){
			REP(j,n){
				if(i&(1<<j)) p[i]|=sum[j];
			}
		}
	//	REP(i,(1<<n)) cout<<p[i]<<' ';cout<<endl;
		for(int i=1;i<(1<<n);i++) {
			//******枚举状态i的所有子集状态j******* 
            for(int j=i;j;j=(j-1)&i) {
                if(p[j]==(1<<n)-1) {
        //        	cout<<"("<<i<<','<<j<<","<<(i^j)<<")"<<' ';
					dp[i]=max(dp[i],dp[i-j]+1);
				}
            }
         //   cout<<endl; 
        }
        printf("Case %d: %d\n",ca++,dp[(1<<n)-1]);
	}
	return 0;
}
/*
3
2 1 2
2 0 2
2 0 1
4
1 1
1 0
1 3
1 2
0
*/
