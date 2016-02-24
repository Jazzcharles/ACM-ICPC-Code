#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int dp[maxn],w[maxn],v[maxn];
int main(){
	int t;
	cin>>t;
	w[1]=150;w[2]=200;w[3]=350;
	while(t--){
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=3;i++){
			for(int j=w[i];j<=n;j++){
				dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
		//		cout<<dp[j]<<' ';
			}
		//	cout<<endl;
		}
		cout<<n-dp[n]<<endl;
	}
	
	return 0;
}
