#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int num[50000],dp[50000],q[50000];
int main(){
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(q,0,sizeof(q));
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		int len=1;
		q[1]=num[1];
	//	dp[1]=1;
		for(int i=2;i<=n;i++){
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(q[mid]<num[i])
					l=mid+1;
				else
					r=mid-1;
			}
			q[l]=num[i];
	//		dp[i]=l;
			len=max(len,l);
		}
	//	for(int i=1;i<=n;i++) cout<<dp[i]<<' ';cout<<endl;	
	//	for(int i=1;i<=len;i++) cout<<q[i]<<' ';cout<<endl;
		printf("%d\n",len);	
	}
	return 0;
}
