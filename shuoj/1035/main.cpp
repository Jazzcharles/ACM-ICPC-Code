#include <iostream>
using namespace std;
char a[100][100];
int n,m,dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
int bfs(int x,int y)
{
	int cnt=0;
	for(int i=0;i<8;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx>=0 && dx<n && dy>=0 && dy<m && a[dx][dy]=='*')
		{
//			cout<<dx<<' '<<dy<<endl;
			cnt++;
		}
		   
	}
	return cnt;
}

int main(int argc, char** argv) {
	int ca=1;
	while(cin>>n>>m && (n||m)){
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
        cout<<"Field #"<<ca++<<":"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='*')
					cout<<"*";
				else
					cout<<bfs(i,j);
			}
			cout<<endl;
		}
        cout<<endl;
	}
	return 0;
}
