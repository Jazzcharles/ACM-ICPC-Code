#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[1000][100];
bool vis[1000][100];

bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m) return 1;
	return 0;
}
int dfs(int x,int y){
	if(!ok(x,y)) return 0;
	if(vis[x][y]) return 0;
	if(a[x][y]=='.') return 0;
	vis[x][y]=1;
	cnt++;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
	return cnt;
}
int main(int argc, char** argv) {
	while(~scanf("%d%d",&m,&n)){
		memset(vis,0,sizeof(vis));
		getchar();
		int ans=0;
		for(int i=0;i<n;i++){
			scanf("%s",a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='*' && !vis[i][j])
				{	
					cnt=0;
					int temp=dfs(i,j);
					ans=max(ans,temp);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
