#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn],w[maxn],v[maxn],f[maxn];
int main(){
	int tm,n;
	scanf("%d%d",&n,&tm);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&w[i]);
//		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tm;j++){
			if(j>=w[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
			else dp[i][j]=dp[i-1][j];
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;
	}
/*	for(int i=1;i<=n;i++){
		for(int j=tm;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+v[i]);
			cout<<f[j]<<' ';
		}
		cout<<endl;
	}
*/	printf("%d\n",dp[n][tm]);
//	cout<<f[tm]<<endl;
	return 0;
}
