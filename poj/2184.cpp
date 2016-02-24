#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn=1e4+5;
int dp[maxn][maxn],w[maxn],m[maxn],v[maxn];

int main(){
	int n,W=0,M=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
			cin>>w[i]>>m[i];
			w[i]+=1000;m[i]+=1000;
			v[i]=w[i]+m[i];
			if(w[i]>=0) W+=w[i];
			if(m[i]>=0) M+=m[i];
	}
//	cout<<W<<' '<<M<<endl;
	int ans=-INF;
	for(int k=1;k<=n;k++){
		for(int i=W;i>=w[k];i--){
			for(int j=M;j>=m[k];j--){cout<<i-w[k]<<' '<<j-m[k]<<endl;
				dp[i][j]=max(dp[i][j],dp[i-w[k]][j-m[k]]+v[k]-2000);
				ans=max(ans,dp[i][j]);
				
				cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}	
		}		
	}
//	cout<<ans<<endl;
	return 0;
}
