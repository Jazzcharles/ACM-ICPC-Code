#include<bits/stdc++.h>
using namespace std;
const int maxn =100;
//p192,p188,p184,p180
int a[maxn],dp[maxn];
//dp[i]:以i结尾的最大子段的和 
int main(){
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	dp[0] = max(0,a[0]);
	int mx = dp[0];
	for(int i = 1; i < n;i++){
		dp[i] = max(dp[i-1]+a[i],a[i]);
		mx = max(mx,dp[i]);
	}
	cout<<mx<<endl;
	for(int i = 0 ; i < n ; i++){
		cout<<dp[i]<<' ';
	}
	cout<<endl;
	
	
	return 0;
}
/*
8
1 -2 3 10 -4 7 2 -5


*/
