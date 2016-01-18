#include <bits/stdc++.h>
using namespace std;
long long a[21][21];
int main(int argc, char** argv) {
	int tx,ty,sx,sy;
	while(cin>>tx>>ty>>sx>>sy){
		memset(a,0,sizeof(a));a[sx][sy]=-1;
		if(sx-2>=0 && sy-1>=0) a[sx-2][sy-1]=-1;
		if(sx-2>=0 && sy+1<=ty) a[sx-2][sy+1]=-1;
		if(sx+2<=tx && sy-1>=0) a[sx+2][sy-1]=-1;
		if(sx+2<=tx && sy+1<=ty) a[sx+2][sy+1]=-1;
		if(sx-1>=0 && sy-2>=0) a[sx-1][sy-2]=-1;
		if(sx-1>=0 && sy+2<=ty) a[sx-1][sy+2]=-1;
		if(sx+1<=tx && sy-2>=0) a[sx+1][sy-2]=-1;
		if(sx+1<=tx && sy+2<=ty) a[sx+1][sy+2]=-1;
		for(int i=0;i<=tx;i++) if(a[i][0]==-1){ a[i][0]=0;break;} else a[i][0]=1;
		for(int j=0;j<=ty;j++) if(a[0][j]==-1){ a[0][j]=0;break;} else a[0][j]=1;
		for(int i=0;i<=tx;i++)
		{
			for(int j=0;j<=ty;j++){
				if(a[i][j]==-1){
					a[i][j]=0;
				}
				else if(i>0 && j>0){
					a[i][j]=a[i-1][j]+a[i][j-1];
				}
	//			cout<<a[i][j]<<' ';
			}
	//		cout<<endl;
		}
		cout<<a[tx][ty]<<endl;
	}
	return 0;
}
