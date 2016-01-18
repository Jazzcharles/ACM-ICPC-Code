#include <bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b)?a:b

int a[80][80],dp[80][80]; 
int main(int argc, char** argv) {
	int n;
	while(cin>>n && n){
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				scanf("%d",&a[i][j]);
			}
		}
		dp[0][0]=a[0][0];
		for(int i=1;i<n;i++){
			for(int j=0;j<=i;j++){
				if(j==0) dp[i][j]=dp[i-1][j]+a[i][j];
				else if(j==i) dp[i][j]=dp[i-1][j-1]+a[i][j];
				else dp[i][j]=max(a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j-1]);
//				cout<<dp[i][j]<<' ';
			}
//			cout<<endl;
		}
		int ans=0;
		for(int j=0;j<n;j++)
		   ans=max(ans,dp[n-1][j]);
		cout<<ans<<endl;
	}
	
	return 0;
}




