#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int main(){
	int n;
	dp[0]=0,dp[1]=dp[2]=dp[3]=1;
	for(int i=4;i<=100001;i++){
		dp[i]=dp[i/2]+1;
	}
	while(scanf("%d",&n) && n){
		printf("Times:%d\n",dp[n]);
	}
	return 0;
}
