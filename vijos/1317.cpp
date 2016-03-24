#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int dp[maxn],w[maxn],v[maxn]; 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)	
	{
		scanf("%d%d",&w[i],&v[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=w[i];j--){
			dp[j]=max(dp[j],dp[j-w[i]]+w[i]*v[i]);
		} 
	}
	printf("%d\n",dp[n]); 
	return 0;
}
