#include<iostream>
#include<cstring>
using namespace std;
int n,cnt,vis[10][10],v[10][10],dir[8][2]={-1,0,1,0,0,-1,0,1,1,-1,1,1,-1,1,-1,-1},a[10][10];
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<n) return 1;
	return 0; 
}
void fill(int x,int y,int f){	
	if(f) vis[x][y]++;
	else vis[x][y]--;
	for(int l=0;l<8;l++){
		int xx=x+dir[l][0];
		int yy=y+dir[l][1];
		while(ok(xx,yy)){
			if(f) vis[xx][yy]++;
			else vis[xx][yy]--;
			xx=xx+dir[l][0];
			yy=yy+dir[l][1];
		} 
	}	
}
void dfs(int x,int y){
	if(x==n-1){
	//	cout<<x<<' '<<y<<endl; 
		cnt++; return; 
	}				
	fill(x,y,1);
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<vis[i][j]<<' ';
//		}
//		cout<<endl;
//	}						
//	cout<<endl;	
	
	for(int i=0;i<n;i++){
		if(!vis[x+1][i]){
			dfs(x+1,i);
		}
	}
	fill(x,y,0);

}
int ans[11];
void init(){
	for(int i=1;i<=10;i++){
		cnt=0;n=i;
		for(int j=0;j<n;j++){
			memset(vis,0,sizeof(vis));
			dfs(0,j);
		}
		ans[n]=cnt;
	}
}
int main(){
	init();
	while(cin>>n,n)
	{
		cout<<ans[n]<<endl;
	}
	
	return 0;
}
