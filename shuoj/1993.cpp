#include<iostream>
#include<cstring>
using namespace std;
int a[105][105];
int main(){
	int m,n;
	while(cin>>n>>m)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			a[x][y]=1;
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(a[i][j]==1 && a[j][k]==1)
						a[i][k]=1;
				}
			}
		}
		int f=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(a[i][j] && a[j][i]) f=1;
			}
		}
		if(f) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
}
