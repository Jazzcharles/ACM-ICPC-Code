#include<iostream>
#define INF 0x3f3f3f3f
#include<cstdio>
#include<cstring>
using namespace std;
int a[10005],dp[10005];
int main(){
	int n;
	while(~scanf("%d",&n),n){
		memset(dp,0,sizeof(dp));
		int flag=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>=0) flag=1;
		}
		if(!flag){
			printf("0 %d %d\n",a[1],a[n]);continue;
		}
		int Max=-INF,start=0,end=n;
		for(int i=1;i<=n;i++){
			dp[i]=max(a[i],dp[i-1]+a[i]);
			if(dp[i]>Max){
				Max=dp[i];end=i;
			}
			//cout<<dp[i]<<' ';
		}
		int sum=0;
		for(int i=end;i>=1;i--){
			sum+=a[i];
			if(sum==Max) {start=i;break;}
		}
		printf("%d %d %d\n",Max,a[start],a[end]);
	
	}
	
	return 0;
}
