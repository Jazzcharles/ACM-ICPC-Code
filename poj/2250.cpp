#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int maxn=105;
string a[maxn],b[maxn],c[maxn];
int cnt,vis[1005][1005],dp[1000][1000];
void print(int i,int j){
	//cout<<i<<' '<<j<<' '<<vis[i][j]<<endl;
	if(!i && !j) return ;
	if(vis[i][j]==2){
		print(i-1,j-1);
		c[cnt++]=a[i-1];
	}
	else if(vis[i][j]==1){
		print(i-1,j);
	}
	else{
		print(i,j-1);
	}
}
int main(){
	while(cin>>a[0]){
		int lena=0;
		while(a[lena]!="#")
			cin>>a[++lena];
		int lenb=0;
		while(b[lenb]!="#")
			cin>>b[++lenb];
		memset(vis,0,sizeof(vis));
		for(int i=0;i<=lena;i++)
			vis[i][0]=1;
		for(int i=0;i<=lenb;i++)
			vis[0][i]=3;
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=lenb;j++){
				if(a[i-1]==b[j-1]){
					vis[i][j]=2;
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else if(dp[i-1][j]>dp[i][j-1]){
					vis[i][j]=1;
					dp[i][j]=dp[i-1][j];
				}
				else{
					vis[i][j]=3;
					dp[i][j]=dp[i][j-1];
				}
			}
		}
		cnt=0;
		print(lena,lenb);
		for(int i=0;i<cnt;i++){
			if(i) cout<<' ';
			cout<<c[i]; 
		}
		cout<<endl;
	}
	
	return 0;
}
