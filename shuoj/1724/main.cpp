#include <bits/stdc++.h>
#define  MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
int m,n,sx,sy,dir[4][2]={{-1,2},{-2,1},{1,2},{2,1}};
bool vis[10][10];
bool ok(int x,int y){
	if(x<=8 && x>=1 && y<=8 && y>=1) return 1;
	return 0;
}
int bfs(int tx,int ty)
{
	int step=0;
	queue<PIII> q;
	q.push(MP(MP(sx,sy),step));
	vis[sx][sy]=1;
	while(!q.empty())
	{
		PIII t=q.front();q.pop();
		int x=t.first.first,y=t.first.second;
		step=t.second;
//		cout<<x<<' '<<y<<' '<<tx<<' '<<ty<<' '<<step<<endl;
		if(x==8 && y==8) return step;
		for(int i=0;i<4;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			if(ok(xx,yy) && !vis[xx][yy])
					q.push(MP(MP(xx,yy),step+1));		
					vis[xx][yy]=1;
		}	
	}
	return -1;
}
int main(int argc, char** argv) {
	while(~scanf("%d%d",&sx,&sy))
	{
		memset(vis,0,sizeof(vis));
		int ans=bfs(8,8);
		if(ans!=-1) cout<<ans<<endl;
		else cout<<"Impossible"<<endl;
	}
	return 0;
}
