#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#define eps 1e-5
using namespace std;
int vis[50][50][50][50],n,m,sx,sy,tx,ty,dir[4][2]={-1,0,0,-1,0,1,1,0};
char a[100][100];
bool near(int x1,int y1,int x2,int y2){
	if(x1==x2 && y1==y2) return 1;
	if(x1==x2+1 && y1==y2) return 1;
	if(x1==x2-1 && y1==y2) return 1;
	if(x1==x2 && y1==y2+1) return 1;
	if(x1==x2 && y1==y2-1) return 1;
//	double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//	if(fabs(d-1)<=eps) return 1;
	return 0;
}
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]!='X') return 1;
	return 0;
}

struct node{
	int sx,sy,zx,zy,k;
};
int bfs(){
	queue<node> q;
	node temp;
	temp.k=0;temp.sx=tx;temp.sy=ty;temp.zx=sx;temp.zy=sy;
	q.push(temp);
	vis[sx][sy][tx][ty]=1;
	while(!q.empty()){
		node t=q.front();
		q.pop();
		int x=t.zx,y=t.zy,xx=t.sx,yy=t.sy,k=t.k;	
		//cout<<x<<' '<<y<<' '<<xx<<' '<<yy<<' '<<k<<endl;
		if(near(x,y,xx,yy)) return k;
	
		for(int i=0;i<4;i++){
			int x1=x+dir[i][0];
			int y1=y+dir[i][1];
			int x2=xx+dir[3-i][0];
			int y2=yy+dir[3-i][1];
			if(!ok(x1,y1)) continue;
			if(ok(x2,y2) && !vis[x1][y1][x2][y2]){
		//		cout<<6666<<endl; 
				node p;
				p.k=k+1;p.sx=x2;p.sy=y2;p.zx=x1;p.zy=y1;
				vis[x1][y1][x2][y2]=1;
				q.push(p);
			}
			if(!ok(x2,y2) && !vis[x1][y1][xx][yy]){
		//		cout<<233<<endl; 
				node p;
				p.k=k+1;p.sx=xx;p.sy=yy;p.zx=x1;p.zy=y1;
				vis[x1][y1][xx][yy]=1;
				q.push(p);	
			}
		}
	}
	return -1;
}
int main(){
	while(cin>>n>>m)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			scanf("%s",a[i]);
			for(int j=0;j<m;j++){
				if(a[i][j]=='Z'){
					sx=i;sy=j;
				}
				if(a[i][j]=='S'){
					tx=i;ty=j;
				}
			}
		}	
		int ans=bfs();
		if(ans==-1) cout<<"Bad Luck!"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
