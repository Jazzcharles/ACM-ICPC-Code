#include <iostream>
using namespace std;
const int maxn=1e5+5;
int dp[maxn];
int main(int argc, char** argv) {
	dp[0]=dp[1]=dp[2]=1;
	dp[3]=2;
	for(int i=4;i<maxn;i++)
		dp[i]=dp[i-1]+dp[i-3]+1;
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}
