#include <bits/stdc++.h>
#include <ios>
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

int main(int argc, char** argv) {
//	ios::sync_with_stdio(false);
	int n,m;
	scanf("%d%d",&n,&m);
	int x;
	set<int > v;
	REP(i,n)
	{
		scanf("%d",&x);
        v.insert(x);
	}   
	REP(i,m){
		scanf("%d",&x);
		if(v.count(x))
		   printf("Yes\n");
		else
		   printf("No\n");
	}    
	return 0;
}




