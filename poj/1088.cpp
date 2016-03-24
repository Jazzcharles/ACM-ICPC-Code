#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,dp[500][500],vis[500][500],a[500][500],dir[4][2]={-1,0,1,0,0,-1,0,1};
bool ok(int x,int y){
	if(x<n && x>=0 && y>=0 && y<m) return 1;
	return 0;
}
int dfs(int x,int y){
	if(dp[x][y]) return dp[x][y];
	int ans=0;
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy) && a[xx][yy]<a[x][y]){
		//	dp[xx][yy]=max(dfs(xx,yy),dp[x][y]+1);
		//	dfs(xx,yy);
			ans=max(ans,dfs(xx,yy));
		}
	}
	dp[x][y]=ans+1;
	return dp[x][y];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans=max(ans,dfs(i,j));
		}
	}
	printf("%d\n",ans);
	return 0;
}
