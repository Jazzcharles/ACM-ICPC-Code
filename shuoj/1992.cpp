#include<iostream>
#include<cstring>
#define INF 0x3f3f3f3f 
using namespace std;
int a[1000];
int sum[1000]; 
int dp[1000][1000];
//dp[i][j]:前i个人选j本书最小和 
int main(){
	int n,k,ca=1;
	while(cin>>n>>k)
	{
		memset(sum,0,sizeof(sum));
		memset(dp,INF,sizeof(dp));
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];	
		}
		for(int i=1;i<=n;i++)
			dp[1][i]=sum[i];
		int ans=0; 
		for(int i=2;i<=k;i++){
			dp[i][0]=0;
			for(int j=i;j<=n;j++){
				for(int l=j-1;l>=1;l--){	
		//			cout<<666<<' '<<dp[i][j]<<' '<<max(dp[i-1][l],sum[j]-sum[l])<<endl;	
					dp[i][j]=min(dp[i][j],max(dp[i-1][l],sum[j]-sum[l]));
				
				}
		//		cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}
		printf("Case %d: %d\n",ca++,dp[k][n]);		
	}
	
	return 0;
}
