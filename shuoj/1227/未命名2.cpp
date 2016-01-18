#include<iostream>
using namespace std;
typedef long long LL;
LL dp[50][50];
void init(){
	dp[0][0]=1; 
	for(int i=1;i<=50;i++){
		for(int j=0;j<=i;j++){
			if(!j) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
}
int main(){
	init();
	int n,m;
	while(cin>>n>>m)
	{
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
