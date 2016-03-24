#include<iostream>
#include<cstring>
using namespace std;
int n,m,vis[105][105],dir[12][2]={-1,0,1,0,0,-1,0,1,-1,1,-1,-1,1,-1,1,1,-2,0,2,0,0,-2,0,2};
char a[105][105];
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]=='#') return 1;
	return 0;	
}
void dfs(int x,int y){
	for(int i=0;i<12;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy) && !vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='#' && !vis[i][j]){
				vis[i][j]=1;
				cnt++;
				dfs(i,j);	
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
