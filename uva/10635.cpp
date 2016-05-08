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
const int maxn=1e5+5;
int a[maxn],b[maxn],dp[maxn],id[maxn];
int main(){
	int t,ca=1;
	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while(t--)
	{
		CLR(dp,0);CLR(id,0); 
		int n,p,q;
		scanf("%d%d%d",&n,&p,&q);
		REP(i,p+1) {
			scanf("%d",&a[i]);
			id[a[i]]=i+1;
		}
		REP(i,q+1) {
			scanf("%d",&b[i]);
			b[i]=id[b[i]];
		}
		int len=1;
		dp[0]=b[0];
		REP2(i,1,q){
			if(!b[i]) continue;
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(dp[mid]<b[i]){
					l=mid+1;
				} 
				else{
					r=mid-1;
				}
			}
			dp[l]=b[i];
			len=max(len,l);
		}
		printf("Case %d: %d\n",ca++,len);
	}
	
	return 0;
}
