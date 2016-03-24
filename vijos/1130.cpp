#include<iostream>
using namespace std;
int dp[1005];
void init(){
	 dp[1]=1;dp[2]=2;dp[3]=2;
	 for(int i=4;i<=1005;i++){
	 	 for(int j=1;j<=i/2;j++){
	 		dp[i]+=dp[j];
		 }
		 dp[i]++;
	 }
}
int main(){
	int n;
	cin>>n;
	init();
	cout<<dp[n]<<endl;
}
