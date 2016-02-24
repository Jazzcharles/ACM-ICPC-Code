#include<iostream>
using namespace std;
const int maxn=1e5+5;
int w[maxn],dp[maxn],v[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[m]<<endl;
	
	return 0;
}
