#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VII;
char s[600][600];
int tot,n,m,k,vis[600][600];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
VII v;
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && s[x][y]=='.') return 1;
	return 0;
}
void dfs(int x,int y){
	if(tot==0) return ;
//	cout<<x<<' '<<y<<' '<<tot<<endl;
	
	int flag=0;
	for(int i=0;i<4;i++){
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(ok(xx,yy) && !vis[xx][yy]){
			vis[xx][yy]=1;
			flag=1;
			dfs(xx,yy);
		}
	}
//	if(!flag) {
		tot--;
		v.push_back(make_pair(x,y));
		
//	}	
}

int main(){
	cin>>n>>m>>k;
	tot=k;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int ff=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='.') {
				vis[i][j]=1;
				dfs(i,j);
				ff=1;
				break;
			}
		}
		if(ff) break;
	}	
//	cout<<v.size()<<endl;
//	for(int i=0;i<v.size();i++){
//		cout<<v[i].first<<' '<<v[i].second<<endl;
//	}	
	for(int i=0;i<k;i++){
		s[v[i].first][v[i].second]='X';
	}
	for(int i=0;i<n;i++){
		printf("%s\n",s[i]);
	}
	
	return 0;
} 
/*
3 4 2
#..#
..#.
#...


2 4 2 
#..#
....


5 4 5
#...
#.#.
.#..
...#
.#.#
*/
