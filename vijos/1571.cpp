#include<iostream>
using namespace std;
const int maxn=1e5+5;
int a[maxn],dp[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=i-1;j>=1;j--){
			if(!(dp[j]%2) && a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
			if((dp[j]%2) && a[i]<a[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
