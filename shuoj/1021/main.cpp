#include<bits/stdc++.h>
using namespace std;

char a[101][101];
int vis[101][101],sx,sy,tx,ty,cnt,n,m;

int dfs(int x,int y,int step){
	if(x==tx&&y==ty){
		return cnt=step;
	}
 //   cout<<x<<' '<<y<<' '<<123<<endl;
	if(vis[x][y]) return 0;
	if(x>=n || x<0 || y>=m || y<0) return 0;
	if(a[x][y]=='#') return 0;
	vis[x][y]=1;
	dfs(x-1,y,step+1);
	dfs(x+1,y,step+1);
	dfs(x,y-1,step+1);
	dfs(x,y+1,step+1); 
	if(!cnt) return -1;
	else return cnt;
}

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while(t--){
	   memset(vis,0,sizeof(vis));
	   scanf("%d%d",&n,&m);	
	   getchar(); 
	   cnt=0;
	   for(int i=0;i<n;i++){
	   	 for(int j=0;j<m;j++){
	      	 scanf("%c",&a[i][j]);
	      	 if(a[i][j]=='S'){
	      	    sx=i;sy=j;
			 }
			 if(a[i][j]=='E'){
			 	tx=i;ty=j;
			 }
		  }
		  getchar();	
	   }
	   cout<<dfs(sx,sy,0)<<endl;
    }
	return 0;
}
