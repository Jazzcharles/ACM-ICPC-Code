#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e6+6;
int dp[maxn],w[maxn],v[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		sum+=w[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
		}
	}
	int ans=INF;
	for(int i=1;i<=sum;i++){
		if(dp[i]>=m){
			ans=min(ans,dp[i]);
		}
	}
	cout<<ans-m<<endl;
	return 0;
}
