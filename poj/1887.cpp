#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int a[maxn],dp[maxn];
int main(){
	int i=0,ca=1;
	while(~scanf("%d",&a[++i]))
	{
		if(a[1]==-1) break;
		if(a[i]==-1){
			int n=i,ans=0;
			for(int k=1;k<=n-1;k++){
				dp[k]=1;
				for(int j=k-1;j>=1;j--){
					if(a[j]>a[k])
						dp[k]=max(dp[k],dp[j]+1);
				}
				ans=max(ans,dp[k]);
			}
			printf("Test #%d:\n  maximum possible interceptions: %d\n\n",ca++,ans);
			memset(a,0,sizeof(a));
			i=0;	
		}
	}
	return 0;
}
