#include<iostream>
#include<cstring>
using namespace std;
int dp[105],a[105][105];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		memset(dp,0,sizeof(dp));
		for(int j=i+1;j<=n;j++){
			int temp=0;
			for(int k=1;k<=n;k++){
				dp[k]+=a[j][k];
				temp=max(temp+dp[k],dp[k]);
				ans=max(ans,temp);
			}
//			for(int f=1;f<=n;f++) cout<<dp[f]<<' ';cout<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
