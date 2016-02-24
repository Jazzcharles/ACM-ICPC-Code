#include<iostream>
#include<cstring>
using namespace std;
const int maxn=500;
int a[maxn],dp[maxn],b[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[n-i+1]=a[i];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			int Max=0;
			for(int j=1;j<=n-i+1;j++){
				if(a[i]>b[j]) Max=max(Max,dp[j]);
				if(a[i]==b[j]) dp[j]=Max+1;
			}
		}
		int ans1=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(dp[i]>=ans1){
				ans1=dp[i];
				if(dp[i]==ans1) cnt1++;
			}
		}
		
	}
	
	return 0;
}
