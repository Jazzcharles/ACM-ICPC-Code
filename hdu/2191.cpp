#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int w[maxn],dp[maxn],v[maxn],num[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>w[i]>>v[i]>>num[i];
		}
		for(int i=1;i<=m;i++){
			for(int k=1;k<=num[i];k++){
				for(int j=n;j>=w[i];j--){
					dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		//			cout<<dp[j]<<' ';
				}
		//		cout<<endl;
			}
		}
		cout<<dp[n]<<endl;
	}	
	return 0;
}
