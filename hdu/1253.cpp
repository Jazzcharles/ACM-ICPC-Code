#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int x,y,z,k;
};
int a,b,c,m,vis[100][100][100],dir[6][3]={-1,0,0,1,0,0,0,-1,0,0,1,0,0,0,1,0,0,-1},s[100][100][100];
bool ok(int x,int y,int z){
	if(x>=0 && x<a && y>=0 && y<b && z>=0 && z<c && !s[x][y][z]) return 1;
	return 0;  
}
int bfs(int x1,int y1,int z1){
	queue<node>q;
	node s;
	s.x=x1;s.y=y1;s.z=z1;s.k=0;
	q.push(s);
	vis[x1][y1][z1]=1;
	while(!q.empty()){
		node t=q.front();q.pop();
		int x=t.x,y=t.y,z=t.z,k=t.k;
		if(x==a-1 && y==b-1 && z==c-1){
			return k<=m?k:-1;
		}
		for(int i=0;i<6;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			int zz=z+dir[i][2];
			if(ok(xx,yy,zz) && !vis[xx][yy][zz]){
				vis[xx][yy][zz]=1;
				node temp;
				temp.x=xx;temp.y=yy;temp.z=zz;temp.k=k+1;
				q.push(temp);	
			} 
		}
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d",&a,&b,&c,&m);
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					scanf("%d",&s[i][j][k]);
				}
			}
		}
		if(s[a-1][b-1][c-1]) {
			printf("-1\n");continue;
		}
		printf("%d\n",bfs(0,0,0));
	}
	return 0;
}
