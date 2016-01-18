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

ll dp[80][80];
void init(){
	for(int j=0;j<=50;j++)
	    for(int i=j;i<=50;i++)
	          if(i==j || j==0) 
				 dp[i][j]=1;
              else if(j==1 && i!=j)
                 dp[i][j]=i;
		   	  else 
		   	     dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
}

int main(int argc, char** argv) {
	int n,m;
	init();
	while(cin>>n>>m){
	//	cout<<dp[n][m]<<endl;
		if(n==0) cout<<25<<endl;
	    else cout<<dp[n+24][n]-dp[2*m][m]*dp[24-m+n-m][n-m]<<endl;
	}
	return 0;
}
