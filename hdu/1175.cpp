#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int f,n,m,a[1005][1005],vis[1005][1005],sx,sy,tx,ty,dir[4][2]={-1,0,0,-1,1,0,0,1};
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m) return 1;
	return 0;
}
void dfs(int x,int y,int k,int turn){
	if(f) return ; 
	if(k>3)return ;
	if(x==tx && y==ty) {
		f=1;return ;
	}
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy) && (!a[xx][yy] || (xx==tx && yy==ty)) && !vis[xx][yy] ){
			vis[xx][yy]=1;
			if(i==turn) dfs(xx,yy,k,turn);
			else dfs(xx,yy,k+1,i);	
			vis[xx][yy]=0;
		}
	}
//	vis[x][y]=0; 
}
int main(){
	ios::sync_with_stdio(false);
	while(~scanf("%d%d",&n,&m),m&&n)
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		int q;
		scanf("%d",&q);
		while(q--){
			memset(vis,0,sizeof(vis));
			f=0;
			scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
			sx--;sy--;tx--;ty--;
			if(a[sx][sy]!=a[tx][ty] || !a[sx][sy]){
				puts("NO");continue;
			}
			vis[sx][sy]=1;
			dfs(sx,sy,0,-1);
			if(f) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
