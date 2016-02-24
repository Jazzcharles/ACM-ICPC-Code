#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
double w[maxn],dp[maxn];
int v[maxn];
int main(){
	double m;int n;
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>m>>n;
		m=1-m;
		int N=0;
		for(int i=1;i<=n;i++){
			cin>>v[i]>>w[i];
			N+=v[i];
			w[i]=1-w[i];		
		}
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=N;j>=v[i];j--){
				dp[j]=max(dp[j],dp[j-v[i]]*w[i]);
		//		cout<<dp[j]<<' ';
			}
		//	cout<<endl;
		}
		int i;
		for(i=N;i>=1;i--){
			if(dp[i]>=m) break;
		}
		cout<<i<<endl;
	}
	
	return 0;
}
