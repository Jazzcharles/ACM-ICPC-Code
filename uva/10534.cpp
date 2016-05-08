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
int a[10005],dp[10005],dpp[10005],q[10005],qq[10005];
int main(){
	int n;
	while(~scanf("%d",&n)){
		CLR(dp,0);CLR(dpp,0);CLR(q,0);CLR(qq,0);
		REP(i,n) scanf("%d",&a[i]);
		int len=1;
		dp[1]=a[0];
		q[0]=1;
		REP2(i,1,n-1){
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(dp[mid]<a[i]) 
					l=mid+1;
				else
					r=mid-1;
			}
			dp[l]=a[i];
			q[i]=l;
			len=max(len,l);
		}
	//	REP(i,n) cout<<q[i]<<' ';cout<<endl;
		int len2=1;
		dpp[1]=a[n-1];
		qq[n-1]=1;
		DEP2(i,n-2,1){
			int l=1,r=len2;
			while(l<=r){
				int mid=(l+r)>>1;
				if(dpp[mid]<a[i])
					l=mid+1;
				else
					r=mid-1;
			}
			dpp[l]=a[i];
			qq[i]=l;
			len2=max(len2,l);
		}
	//	REP(i,n) cout<<qq[i]<<' ';cout<<endl;
		int ans=min(q[0],qq[0]);
		REP(i,n){
			ans=max(ans,min(q[i],qq[i]));
		}
		printf("%d\n",ans*2-1);
	}
	return 0;
}
/*

10
1 2 3 4 5 4 3 2 1 10
19
1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1
5
1 2 3 4 5
*/ 
