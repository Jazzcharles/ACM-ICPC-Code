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

int q[maxn],a[maxn],c[maxn];
int main(int argc, char** argv) {
	int  n, k;
    int l = 0, r = 0, ans = INF;
    int t;
	cin>>t;
	while(t--){
		memset(q,0,sizeof(q));
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&k);
		REP(i,n) scanf("%d",&a[i]);
		int j=0;
		for(int i = 0; i < n; i++) {
           while(l<r && a[q[r]] > a[i]) r--;
           q[r++] = i;
     //      cout<<a[q[l]]<<endl;
           if(i >= k-1) c[j++]=a[q[l++]];
		   //ans = min(ans, a[q[l]]);
        }
        printf("%d",c[0]);
        for(int i=1;i<=n-k;i++)
           printf(" %d",c[i]);
		printf("\n");
	}
	return 0;
}
