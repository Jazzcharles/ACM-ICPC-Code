#include<iostream>
#include<cstring>
using namespace std;
int n,vis[10][10],ans,dir[4][2]={-1,0,1,0,0,-1,0,1};
char a[10][10]; 
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<n) return 1;
	return 0;
} 
void fill(int x,int y,int k){
	if(k){
		int i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i--][j]++;
		i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i][j--]++;
		i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i++][j]++;
		i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i][j++]++;		
	}
	else{
		int i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i--][j]--;
		i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i][j--]--;
		i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i++][j]--;
		i=x,j=y;
		while(ok(i,j) && a[i][j]!='X') vis[i][j++]--;	
	}
}

void dfs(int cnt){	
	ans=max(ans,cnt);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){	
			if(!vis[i][j] && a[i][j]=='.'){
			//	cout<<i<<' '<<j<<' '<<vis[i][j]<<' '<<cnt<<endl;
				fill(i,j,1);
			 	dfs(cnt+1);
			 	fill(i,j,0);
			} 				
		}	
	}
} 
int main(){
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		ans=0;
		memset(vis,0,sizeof(vis));
		dfs(0);
		cout<<ans<<endl;
	}
	
	return 0;
}
