#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string> 
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
#define MP(a,b) make_pair(a,b)
int vis[10][10],sx,sy,tx,ty,dir[8][2]={-1,-2,-1,2,1,-2,1,2,-2,1,-2,-1,2,1,2,-1};
bool ok(int x,int y){
	if(x>=0 && x<8 && y>=0 && y<8) return 1;
	return 0;
}
int bfs(){
	vis[sx][sy]=1;
	queue<PIII> q;
	q.push(MP(MP(sx,sy),0));
	while(!q.empty()){
		PIII t=q.front();q.pop();
		int x=t.first.first;
		int y=t.first.second;
		int k=t.second;
	//	cout<<x<<' '<<y<<' '<<k<<endl;
		if(x==tx && y==ty) return k;
		for(int i=0;i<8;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			if(ok(xx,yy) && !vis[xx][yy]){
				vis[xx][yy]=1;
				q.push(MP(MP(xx,yy),k+1));
			}
		}	
	}
	return -1; 
}
int main(){
	string s,ss;
	while(cin>>s){
		cin>>ss;
		memset(vis,0,sizeof(vis));
		sx=s[0]-'a';sy=s[1]-'1';
		tx=ss[0]-'a';ty=ss[1]-'1';
	//	cout<<sx<<' '<<sy<<' '<<tx<<' '<<ty<<endl;
		printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],ss[0],ss[1],bfs());
	}
	
	return 0;
}
