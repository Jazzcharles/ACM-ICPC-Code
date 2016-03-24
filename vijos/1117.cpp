#include<iostream>
using namespace std;
int dp[250][20];
//dp[i][j]:把i划分成j份需要的总共次数 
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=250;i++)
		dp[i][1]=1;
	for(int i=1;i<=250;i++){
		dp[i][i]=1;
		for(int j=2;j<=i && j<=k;j++){
			dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
		}
	}
	cout<<dp[n][k]<<endl;
	
	return 0;
}
