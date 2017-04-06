#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+500;
ll a[maxn];
ll dp[maxn][2];
int main(){
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dp[0][0] = dp[0][1] = 0;
	//dp[i][0]:i结尾的最大和,当前为加,dp[i][1],当前为减 
	ll ans = 0;
	for(int i = 1 ; i < n ; i++){
		dp[i][0] = max(dp[i-1][1]+abs(a[i]-a[i-1]),abs(a[i]-a[i-1]));
		dp[i][1] = max(dp[i-1][0]-abs(a[i]-a[i-1]),-abs(a[i]-a[i-1]));
		//cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
		ans = max(ans,max(dp[i][0],dp[i][1]));
	}
	cout<<ans<<endl;
	//cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
	
	
	
	return 0;
}
/*
5
1 4 2 3 1

4
1 5 4 7


50
-5 -9 0 44 -10 37 34 -49 11 -22 -26 44 8 -13 23 -46 34 12 -24 2 -40 -15 -28 38 -40 -42 -42 7 -43 5 2 -11 10 43 9 49 -13 36 2 24 46 50 -15 -26 -6 -6 8 4 -44 -3

*/
