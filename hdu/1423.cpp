#include<iostream>
#include<cstring>
using namespace std;
int a[505],b[505];
int dp[505],q[505][505];
int main(){
	int t;
	cin>>t;
	while(t--)
	{	
		memset(dp,0,sizeof(dp));
		int m,n;
		cin>>m;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=m;i++){
			int Max=0;
			for(int j=1;j<=n;j++){
				if(a[i]>b[j]) Max=max(Max,dp[j]);
				if(a[i]==b[j]) dp[j]=Max+1;
	//			cout<<dp[j]<<','<<Max<<' ';
			}
	//		cout<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
	//		cout<<dp[i]<<' ';
			ans=max(ans,dp[i]);
		}
	//	cout<<endl;
		cout<<ans<<endl;
		if(t) cout<<endl;
	}	

	return 0;
}

