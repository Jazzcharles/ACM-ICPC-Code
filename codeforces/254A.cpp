#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[500][500];
int vis[500][500];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int tot;
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && s[x][y]=='.') return 1;
	return 0;
}

void dfs(int x,int y)
{
	
	
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy) && !vis[xx][yy]){
			if(vis[x][y]==1){
				vis[xx][yy]=2;
				//cout<<xx<<' '<<yy<<' '<<vis[xx][yy]<<' '<<666<<endl;
				dfs(xx,yy);
			}
			else if(vis[x][y]==2){
				vis[xx][yy]=1;
				//cout<<xx<<' '<<yy<<' '<<vis[xx][yy]<<' '<<777<<endl;
				dfs(xx,yy);
			}
		}
	}
	
	
	
}
	
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++){
			if(s[i][j]=='-'){
				vis[i][j]=-1;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]){
				vis[i][j]=1;
			//	cout<<i<<' '<<j<<endl;
				dfs(i,j);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==1){
				cout<<'B';
			}
			else if(vis[i][j]==2){
				cout<<'W';
			}
			else cout<<'-';
		}
		cout<<endl;
	}
	
	
	return 0;
} 

/*

1 1
.

2 2
..
..

3 3
.-.
---
--.


4 4
....
....
....
....


*/
