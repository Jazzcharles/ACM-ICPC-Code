#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000][1000];
int v[1000][1000];
int f[505][505];
struct node{
	int sx,sy,tx,ty;
}ans[505];
int dir[4][2] = {-1,0,1,0,0,-1,0,1};
int sx,sy,tx,ty;
bool ok(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m && a[x][y]) return 1;
	return 0;
}


void dfs(int x,int y){
	f[x][y]=1;
	for(int i = 0 ; i< 4; i++){
		int xx = x+dir[i][0];
		int yy = y+dir[i][1];
		if(ok(xx,yy) && !v[xx][yy]){
			v[xx][yy]=1;
			sx = min(sx,xx);
			sy = min(sy,yy); 
			tx = max(tx,xx);
			ty = max(ty,yy);
			dfs(xx,yy);
		//	a[xx][yy] = 0;		
		}
		
	}
}
char s[505];
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; i++){
		for (int j = 0 ; j< m ;j++){
			//cin>>a[i][j];
			char ch;
			cin>>ch;
			if(ch=='1') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	int ct = 0;
	for(int j = 0; j<m; j++){
		for(int i= 0 ; i< n ; i++){
			if(!v[i][j] && a[i][j]){
				v[i][j]=1;
				sx = tx = i;
				sy = ty = j;
				//cout<<i<<' '<<j<<endl;
				dfs(i,j);
				int minx = min(sx,tx);
				int maxx = max(sx,tx);
				int miny = min(sy,ty);
				int maxy = max(sy,ty);
				printf("%d %d\n",abs(maxx-minx)+1,abs(maxy-miny)+1);
				for(int j = minx; j <= maxx ; j++){
					for(int k = miny; k<=maxy ; k++){
						if(f[j][k]) {
							printf("1");	
							f[j][k]=0;
						}
						else printf("0");
						//a[j][k] = 0;
					}
					printf("\n");
				} 				

			}
		}
	}

	
	
	
	return 0;
}
/*
11 17
00000000000000000
00001111111100000
00000000000000000
00111111111111100
00000000100000000
00000010101110000
00000110100011000
00011100100001000
00000010100000000
00000001100000000
00000000000000000




*/
