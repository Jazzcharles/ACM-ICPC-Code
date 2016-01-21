#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;
char a[10][10]; 
int n,m,t,sx,sy,tx,ty,flag,vis[10][10],dir[4][2]={-1,0,1,0,0,-1,0,1};
bool ok(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m || a[x][y]=='X')
		return 0;
	return 1;
}

void dfs(int x,int y,int cnt){
	if(!ok(x,y)||cnt>t||flag) return ;
	if(x==tx && y==ty && cnt==t) {
		flag=1;return ;
	}
	int temp=abs(x-tx)+abs(y-ty)-abs(t-cnt);
	if(temp>0 || temp%2) return ;
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy)&&!vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy,cnt+1);
			vis[xx][yy]=0;
		}
	}
	return ;
}

int main(int argc, char** argv) {
	while(~scanf("%d%d%d",&n,&m,&t))
	{
		if(!n && !m && !t) break;
		getchar();
		flag=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++){
				scanf("%c",&a[i][j]);
				if(a[i][j]=='S')
					sx=i,sy=j;
				if(a[i][j]=='D')
					tx=i,ty=j; 
			}
			getchar();
		}
		memset(vis,0,sizeof(vis));
		vis[sx][sy]=1;
		dfs(sx,sy,0);
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
	return 0;
}
