#include <iostream>
using namespace std;
int a[105],dp[205][205];
int main(int argc, char** argv) {
	int n,e=0,sx,sy;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[i]=a[n+i]=x;
	}
	for(int j=2;j<=2*n;j++){
		for(int i=j-1;i>=1&&j<n+i;i--){
			for(int k=i;k<j;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		
		}
	}
	int ans=0;
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
			ans=max(ans,dp[i][j]);
	cout<<ans<<endl;
	return 0;
}
