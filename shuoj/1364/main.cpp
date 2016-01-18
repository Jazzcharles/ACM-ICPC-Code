#include <bits/stdc++.h>
using namespace std;
const int maxn=4e3+5;
int a[25],dp[25],nex[25];
int main(int argc, char** argv) {
		char ch;
		int n=0;
		while(scanf("%d%c",&a[n++],&ch))
			if(ch=='\n') break;
		memset(dp,0,sizeof(dp));
		memset(nex,0,sizeof(nex));
		nex[0]=0;	
		for(int i=0;i<n;i++){
			int temp=0,tmp=0;
			dp[i]=1,nex[i]=1;
			for(int j=i-1;j>=0;j--){
				if(a[j]>=a[i] && temp<dp[j]){
					temp=dp[j];
				}
				if(a[j]<a[i] && tmp<nex[j]){
					tmp=nex[j];
				}
			}
			dp[i]=temp+1,nex[i]=tmp+1;
		}
//		for(int i=0;i<n;i++)
//			cout<<next[i]<<' ';
		
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(dp[i],ans); 
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			cnt=max(nex[i],cnt);
		}
		printf("%d,%d\n",ans,cnt-1);
	return 0;
}
