#include<iostream>
#define INF 0x3f3f3f3f
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int dp[maxn],v[maxn],w[maxn];
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		int m=r-l;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>v[i]>>w[i];
		memset(dp,INF,sizeof(dp));	
		dp[0]=0;
		for(int i=1;i<=n;i++){
			for(int j=w[i];j<=m;j++){
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
	//			cout<<dp[j]<<' ';
			}
	//		cout<<endl;
		}
		if(dp[m]==INF) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
	}
	return 0;
}
/*
3
10 110
2
1 1
30 50

10 110
2
1 1
50 30

1 6
2
10 3
20 4
*/
