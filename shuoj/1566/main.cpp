#include <iostream>
#include<queue>
#include<cstring>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
int a[5][5],vis[5][5],dir[4][2]={-1,0,1,0,0,-1,0,1};
PII pre[5][5];
bool ok(int x,int y){
	if(x>=0 && x<5 && y>=0 && y<5 && !a[x][y]) return 1 ;
	return 0;
}

int bfs(){
	queue<PII> q;
	q.push(MP(0,0));
	pre[0][0].first=-1;
	pre[0][0].second=-1;
	while(!q.empty()){
		PII p=q.front();q.pop();
		int x=p.first,y=p.second;
		if(vis[x][y]) continue;
		vis[x][y]=1;
		if(x==4 && y==4) return 1;
		for(int i=0;i<4;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			if(!vis[xx][yy] && ok(xx,yy)){
				q.push(MP(xx,yy));
				pre[xx][yy].first=x;
				pre[xx][yy].second=y;
		//		cout<<xx<<' '<<yy<<endl;
		//		cout<<pre[xx][yy].first<<' '<<pre[xx][yy].second<<endl;
			}
				
		}
	}
	return -1;
}
void dfs(int x,int y){
	if(x!=-1 && y!=-1)
	{
		dfs(pre[x][y].first,pre[x][y].second);
		cout<<"("<<x<<", "<<y<<")"<<endl;
	}	
	return ;
}
int main(int argc, char** argv) {
	int t,ca=1;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)
				scanf("%d",&a[i][j]);
		}
		cout<<"Case "<<ca++<<":"<<endl;
		bfs();
		dfs(4,4);
	}
	return 0;
}
