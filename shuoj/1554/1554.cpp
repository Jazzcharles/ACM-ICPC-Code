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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn=1e5+5;
const int mod=1e9+7;
const int B=1031;

int Map[100][100];
int vis[100][100];
int n,m;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool bfs(){
	queue<int >q;
	q.push(0);
	vis[0][0]=1;
	while(!q.empty()){
		int t=q.front();q.pop();
		int x=t/m, y=t%m;
		if(x==n-1 && y==m-1)
		  return 1;
		REP(i,4)
		{
		    int tx=x+dir[i][0];
			int ty=y+dir[i][1];	
			if(tx>=0 && tx<n && ty>=0 && ty<m && vis[tx][ty]==0 && Map[tx][ty]==0)
		    {
		    	vis[tx][ty]=1;
		    	q.push(tx*m+ty);
			}
		} 
		
	}
	return 0;
}
	
int main(int argc, char** argv) {
	while(cin>>n>>m){
		memset(vis,0,sizeof(vis));
		REP(i,n)
		  REP(j,m)
		    scanf("%d",&Map[i][j]);
	    if(bfs())
		   cout<<"Y"<<endl;
		else
		   cout<<"N"<<endl;	
		
		
		
	}
	return 0;
}
