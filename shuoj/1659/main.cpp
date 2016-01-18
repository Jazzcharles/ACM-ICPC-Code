#include<bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef vector<int> VI;
int a[8][8],sx,sy,tx,ty;
bool vis[8][8];
int dir[8][2]={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
struct node{
	int x,y,step;
};
bool ok(int x,int y){
	if(x<8 && x>=0 && y<8 && y>=0)
	     return 1;
	return 0;
}

int bfs(){
	int ans=0;
	node t,p;
	queue<node>q;
	t.x=sx,t.y=sy,t.step=0;
	q.push(t);
	vis[sx][sy]=1;
	while(!q.empty()){
		t=q.front();
		q.pop();
		int x=t.x,y=t.y,step=t.step;
		if(x==tx && y==ty) break;
		for(int i=0;i<8;i++){
			int dx=x+dir[i][0];
			int dy=y+dir[i][1];
			if(ok(dx,dy)&&vis[dx][dy]==0){
//				  cout<<dx<<' '<<dy<<endl;
				  vis[dx][dy]=1;
				  p.x=dx,p.y=dy,p.step=step+1;
				  q.push(p);
			}
		}
	}
	return t.step;
}

int main(int argc, char** argv) {
	char ch1,ch2;int w1,w2;
	while(cin>>ch1>>w1){
		getchar();
		cin>>ch2>>w2;
		memset(vis,0,sizeof(vis));
		sx=ch1-'a';
		sy=w1-1;
		tx=ch2-'a';
		ty=w2-1;
		cout<<ch1<<w1<<"==>"<<ch2<<w2<<": "<<bfs()<<" moves"<<endl;
	}
	
	
	
	return 0;
}
