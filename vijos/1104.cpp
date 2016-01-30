#include<iostream>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e5+5;
int w[maxn],v[maxn],dp[maxn];
int main(){
	int n,m;
	cin>>m>>n;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);	
	//		cout<<dp[j]<<' ';
		}
	//	cout<<endl;
	}

	cout<<dp[m]<<endl;
	return 0;
}
