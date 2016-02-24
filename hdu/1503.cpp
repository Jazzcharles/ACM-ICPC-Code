#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[150][150],vis[150][150];
char a[150],b[150];
void print(int i,int j){
	if(!i && !j) return ;
	if(vis[i][j]==2){
		print(i-1,j-1);
		printf("%c",a[i-1]);
	}
	else if(vis[i][j]==1){
		print(i-1,j);
		printf("%c",a[i-1]);
	}
	else{
		print(i,j-1);
		printf("%c",b[j-1]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(~scanf("%s%s",a,b))
	{
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int lena=strlen(a),lenb=strlen(b);
		for(int i=0;i<=lena;i++) vis[i][0]=1;
		for(int i=0;i<=lenb;i++) vis[0][i]=3;
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=lenb;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
					vis[i][j]=2;
				}
				else if(dp[i-1][j]>=dp[i][j-1]) {
					dp[i][j]=dp[i-1][j];	
					vis[i][j]=1;
				}
				else{
					dp[i][j]=dp[i][j-1];
					vis[i][j]=3;	
				}
			}
		}
//		for(int i=1;i<=lena;i++){
//			for(int j=1;j<=lenb;j++){
//				cout<<vis[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		print(lena,lenb);
		printf("\n");
	//	cout<<dp[lena][lenb]<<endl;
	}
	
	return 0;
}
