#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt,n,m,vis[25][25],dir[4][2]={-1,0,1,0,0,-1,0,1};
char a[25][25];
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]=='.') return 1;
	return 0; 
}

void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy) && !vis[xx][yy]){
			vis[xx][yy]=1;
			cnt++;
			dfs(xx,yy);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>m>>n)
	{
		if(!m && !n) break; 
		int x=0,y=0;
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			for(int j=0;j<m;j++){
				if(a[i][j]=='@'){
					x=i,y=j;
				}
			}
		}
		vis[x][y]=1;
		dfs(x,y);
		cout<<cnt+1<<endl;
	}
	
	return 0;
}
