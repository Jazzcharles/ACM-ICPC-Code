#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5e5+5;
int dp[maxn],a[maxn];
int main(){
	int n,ca=1;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		memset(dp,0,sizeof(dp));
		int len=1;
		dp[1]=a[1];
		for(int i=1;i<=n;i++){
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(dp[mid]<a[i])
					l=mid+1;
				else
					r=mid-1;
			}
			dp[l]=a[i];
			len=max(len,l);
		}
		if(len==1)
			printf("Case %d:\nMy king, at most %d road can be built.\n",ca++,len);	
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n",ca++,len);
		puts("");
	}
	return 0;
}
