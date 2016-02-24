#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
int dp[maxn];//dp[i],1~i层的最大和 
struct node{
	int x,y;
}a[maxn];
int dis(int u,int v){
	return (abs(a[u].x-a[v].x)+abs(a[u].y-a[v].y))*(abs(a[u].x-a[v].x)+abs(a[u].y-a[v].y));
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t;cin>>t;
			a[t].x=i;
			a[t].y=j;
		}
	}
	for(int i=1;i<=n*n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
				dp[i]=max(dp[i],dp[j]+dis(i,j));
		}
	}
	cout<<dp[n*n]<<endl;
	return 0;
}
