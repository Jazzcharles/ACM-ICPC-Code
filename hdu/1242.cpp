#include <iostream>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII; 
typedef vector<PIII> VIII;
int n,m,a[1000][1000],vis[1000][1000],dir[4][2]={-1,0,1,0,0,-1,0,1};
bool ok(int x,int y){
	if(x<0 || x>=n || y<0 || y>=m || a[x][y]=='#') return 0;
	return 1;
}
int bfs(int x,int y){
	priority_queue<PIII,VIII,greater<PIII> > q;
	q.push(MP(0,MP(x,y)));
	while(!q.empty()){
		PIII t=q.top();q.pop();
		int x=t.second.first,y=t.second.second,step=t.first;
		if(vis[x][y]) continue;
		vis[x][y]=1;
		if(a[x][y]=='a') return step;
		for(int i=0;i<4;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			if(ok(xx,yy) && !vis[xx][yy]){
				if(a[xx][yy]=='x') q.push(MP(step+2,MP(xx,yy)));
				else q.push(MP(step+1,MP(xx,yy)));
			}
		} 
	}
	return -1;
}
int main(int argc, char** argv) {
	while(cin>>n>>m && (n||m))
	{
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
		int ans=INF; 
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='r'){
					memset(vis,0,sizeof(vis));
					int t=bfs(i,j);
				//	cout<<t<<endl;
					if(t>0) ans=min(t,ans); 
				}
			}
		}
		if(ans==INF) cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
