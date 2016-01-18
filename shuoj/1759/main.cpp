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

int a[10][10],vis[10],cnt,flag;
int dfs(int x,int y){	 
	if(vis[a[x][y]]==1) return 0;
	vis[a[x][y]]=1;
	if(x==8){
		flag=1;return 1;
	} 
    cout<<x<<' '<<y<<' '<<' '<<a[x][y]<<' '<<vis[a[x][y]]<<endl;
    
	cnt=1+dfs(x+1,y)+dfs(x+1,y+1);
/*	for(int i=1;i<10;i++)
	   for(int j=0;j<i;j++){
	   	  
	   }
	
*/	if(flag)
    return 1;
    else
    return 0;
//	cout<<cnt<<endl;
}



int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(n--){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<9;i++)
		  for(int j=0;j<=i;j++){
		  	  scanf("%d",&a[i][j]);
		}
		if(dfs(0,0)) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;	
	}
	return 0;
}




