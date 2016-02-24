#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
LL w[maxn],dp[maxn],v[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=n;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		cout<<dp[m]<<endl;			
	}

	return 0;
}
