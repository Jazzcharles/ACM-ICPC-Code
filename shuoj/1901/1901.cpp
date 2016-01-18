#include <bits/stdc++.h>
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

char a[5][5];
int vis[5][5];
int sx,sy,res,dis,n,m;

bool in(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m )
	   return 0;
	return 1;
}

int dfs(int x, int y){
	if(x==sx && y==sy)
	    res++;
	if(res==2) 
	    return 1;
	if(!in(x,y) || a[x][y]=='X' || vis[x][y])
	    return 0;
	int t;
	vis[x][y]=1;
//	cout<<123<<endl;
	    if(a[x][y]=='0')
	       t=1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);
	return t;
}


int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)
    {
    	memset(vis,0,sizeof(vis));
	    int cnt=0,res=0;
	    cin>>n>>m;
	    getchar();
	    REP(i,n)
	      REP(j,m)
	      {
	         	cin>>a[i][j];
	         	if(a[i][j]=='S')
	         	{
	         		sx=i;sy=j;
				}
				if(a[i][j]=='0')
				    cnt++;
		  }
        cout<<dfs(sx,sy)<<endl;

	
	}	
	return 0;
}




