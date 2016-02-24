#include<iostream>
#include<cstring>
using namespace std;
int dp[1005][1005];
//dp[i][j]第一串从0~i，第二串从0~j的最长公共子序列的长度 
int main(){
	string a,b;
	while(cin>>a>>b) 
	{
		memset(dp,0,sizeof(dp));
		int lena=a.length()-1,lenb=b.length()-1;
		for(int i=0;i<a.length();i++){
			for(int j=0;j<b.length();j++){
				if(a[i]==b[j]){
					if(i>0 && j>0)	 dp[i][j]=dp[i-1][j-1]+1;
					else dp[i][j]=1;
				}
				if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
		//		cout<<dp[i][j]<<' ';
			}
		//	cout<<endl;
		}
		cout<<dp[lena][lenb]<<endl;
	}
	
	return 0;
}
