#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;

struct node{	
	int x,y,k;
	friend bool operator < (node a,node b){
		return a.k>b.k;
	} 
};

int sx,sy,tx,ty,sd,pt,tr,vis[30][30],n,m,dir[4][2]={-1,0,1,0,0,-1,0,1};
char a[30][30];
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]!='@') return 1;
	return 0;
}

int bfs(){
	priority_queue<node> q;
	node s;
	s.x=sx;s.y=sy;s.k=0;
	q.push(s);
	vis[sx][sy]=1;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int x=t.x,y=t.y,num=t.k;
		for(int i=0;i<4;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			int tt=0;
			if(ok(xx,yy) && !vis[xx][yy]){
				if(a[xx][yy]=='T') tt+=tr;
				if(a[xx][yy]=='.') tt+=sd;
				if(a[xx][yy]=='#') tt+=pt;
				vis[xx][yy]=1;
				if(xx==tx && yy==ty){
					return tt+num; 
				}
				//cout<<xx<<' '<<yy<<' '<<num+tt<<endl;
				node temp;
				temp.x=xx;temp.y=yy;temp.k=tt+num;
				q.push(temp);
			}
		}
	}
	return -1;
	//return ans==INF?-1:ans;
}
int main(){
	ios::sync_with_stdio(false);
	int ca=1;
	while(cin>>n>>m){
		cin>>pt>>sd>>tr;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cin>>sx>>sy>>tx>>ty;
		int ans=bfs();
		printf("Case %d: %d\n",ca++,ans);
	}
	return 0;
}
