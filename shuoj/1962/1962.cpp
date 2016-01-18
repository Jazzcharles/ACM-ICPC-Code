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

int dis[120][120][2];
char a[120][120];
bool vis[100][100];
int sx,sy,tx,ty,xx,yy,m,n;
// Ë®1 »ð0 

bool status(int nature){
	if(xx<0 || xx>=n || yy<0 || yy>=m)
	  return 0;
	if(nature==0 && a[xx][yy]=='~')
	  return 0;
	if(nature==1 && a[xx][yy]=='w')
	  return 0;
	if(a[xx][yy]=='#')
	  return 0;
	return 1;
}

int bfs(){
	int x,y,nature;
	queue<pair<PII,int> >q;
	q.push(MP(MP(sx,sy),1));
    while(!q.empty()){
     // cout<<q.size()<<endl;
    	x=q.front().X.X;
    	y=q.front().X.Y;
    	int nature=q.front().Y;
    	q.pop();
    	if(x==tx && y==ty)
    	  return dis[x][y][nature];
    	for(int i=0;i<4;i++){
    		xx=x+dir[i][0];
    		yy=y+dir[i][1];
    		if(!status(nature)) continue;
    		if(dis[xx][yy][nature]== -1){
    //         	cout<<xx<<' '<<yy<<' '<<endl;
    			dis[xx][yy][nature]=dis[x][y][nature]+1;
    			q.push(MP(MP(xx,yy),nature));
    //			cout<<dis[xx][yy][nature]<<endl;
			}
		}	
		if(a[x][y]=='@'){
			if(dis[x][y][!nature]== -1){
				dis[x][y][!nature]=dis[x][y][nature]+1;
				q.push(MP(MP(x,y),!nature));
			}
		}
	}
	if(x!=tx || y!=ty)
	return -1;
}


int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		getchar();
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			for(int j=0;j<m;j++){
				if(a[i][j]=='S'){
					sx=i;sy=j;
				}
				if(a[i][j]=='T'){
					tx=i;ty=j;
				}
			}
		}
//		cout<<sx<<' '<<sy<<endl;
		memset(dis,-1,sizeof(dis)); 
		dis[sx][sy][1]=0;  
		int ans=bfs();
//		cout<<ans<<endl;
		if(ans==-1)
		  cout<<"Sad Yaoge!"<<endl;
		else   
		  cout<<ans<<endl;
	}
	return 0;
}
