#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[2][5005];
char a[5005],b[5005];
int main(){
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		string a,b;
		cin>>a;
		b=a;
		reverse(a.begin(),a.end());
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int x=i%2;
				int y=x^1;
				if(a[i-1]==b[j-1]){
					dp[x][j]=dp[y][j-1]+1;
				}
				else{
					dp[x][j]=max(dp[y][j],dp[x][j-1]);
				}
			}
		}
		cout<<n-dp[n%2][n]<<endl;		
	}

	return 0;
}
