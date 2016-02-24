#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int w[maxn];
double dp[maxn],v[maxn];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m),m||n)
	{
		for(int i=1;i<=m;i++){
			scanf("%d%lf",&w[i],&v[i]);
		}
		fill(dp,dp+maxn,1);
		for(int i=1;i<=m;i++){
			for(int j=n;j>=w[i];j--){
				dp[j]=min(dp[j],dp[j-w[i]]*(1-v[i]));
			}
		}
		printf("%.1f%%\n",100*(1-dp[n]));
	}
	
	
	return 0;
}
