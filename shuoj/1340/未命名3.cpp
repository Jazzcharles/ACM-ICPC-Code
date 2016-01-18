#include<iostream>
using namespace std;
long long dp[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i<m) dp[i]=2*dp[i-1];
		else if(i==m) dp[i]=2*dp[i-1]-1;
		else dp[i]=dp[i-1]*2-dp[i-m-1];
	}
	cout<<dp[n]<<endl; 
	return 0;
} 
