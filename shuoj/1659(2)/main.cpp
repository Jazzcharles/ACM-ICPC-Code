#include<bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<pair<int,int>,int> PIII;
int a[8][8],sx,sy,tx,ty;
bool vis[8][8];
int dir[8][2]={{-2,-1},{2,-1},{-2,1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};

inline bool ok(int x,int y){
	if(x<8 && x>=0 && y<8 && y>=0)
	     return 1;
	return 0;
}

int bfs(){
	int ans=0,x,y,step;
	queue<PIII>q;
	q.push(MP(MP(sx,sy),0));
	vis[sx][sy]=1;
	while(!q.empty()){
		PIII p=q.front();
		q.pop();
		x=p.first.first,y=p.first.second,step=p.second;
		if(x==tx && y==ty) break;
		for(int i=0;i<8;i++){
			int dx=x+dir[i][0];
			int dy=y+dir[i][1];
			if(ok(dx,dy)&&vis[dx][dy]==0){
				  vis[dx][dy]=1;
				  q.push(MP(MP(dx,dy),step+1));
			}
		}
	}
	return step;
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
