#include<iostream>
using namespace std;
int a[1005][1005],dp[1005][1005];
int Min(int a,int b,int c){
	a=min(a,b);
	return min(a,c);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j])
				dp[i][j]=Min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1;
			ans=max(ans,dp[i][j]);
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;	
			
	}
	cout<<ans<<endl;
	return 0;
}
