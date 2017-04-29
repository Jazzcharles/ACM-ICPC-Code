#include<bits/stdc++.h>
using namespace std;

int bf(int n){
	int ct = 0;
	for(int i = 1; i <=n;i++){
		int j = i;
		while(j){
			if(j%10==1) ct++;
			j/=10;
		}
	}
	return ct;
}

int dp[10][10];
int f[10]={0,1,10,100,1000,10000,100000} ;
//dp[i][j]:i位数以j开头的1的个数
void init(){
	for(int i=1;i<=5;i++){
		for(int j = 0;j<10;j++){//第i位为j
			if(j==1) dp[i][j] = dp[i-1][9]*2+f[i];
			else dp[i][j] = dp[i][j-1]+dp[i-1][9];
		}
	}
} 
//121
int solve(int n){
	int res[20]={0};	
	int tot = 1; 
	while(n){
		res[tot++]=n%10;
		n/=10;
	}
	//for(int i=tot-1;i>=0;i--) cout<<res[i]<<endl;
	int ans = 0;
	for(int i=tot-1;i>0;i--){
		int num = res[i];
		if(!num) continue ;
		//cout<<num<<endl;
		int s = 0;
		for(int j=i-1;j>0;j--){
			s=s*10+res[j];
		}
		if(num==1)
			ans += s+dp[i-1][9]+1;
		else
			ans += dp[i][num-1];
		cout<<"debug "<<ans<<endl;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<bf(n)<<endl;
	init();
	//cout<<dp[2][9]<<endl;
	cout<<solve(n)<<endl;
	return 0;
} 
