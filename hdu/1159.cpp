#include<iostream>
#include<cstring>
using namespace std;
int dp[1005][1005];
int main(){
	string a,b;
	while(cin>>a>>b)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<a.length();i++){
			for(int j=0;j<b.length();j++){
				if(a[i]==b[j]){
					if(i>0 && j>0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					else dp[i][j]=1;
				}
				if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			}
		}
		cout<<dp[a.length()-1][b.length()-1]<<endl;
	}
	return 0;
}
