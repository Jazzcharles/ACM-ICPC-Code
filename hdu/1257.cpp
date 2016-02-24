#include<iostream>
#include<cstring>
using namespace std;
int dp[30005],a[30005];
int main(){
	int n;
	while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int len=1;
		dp[1]=a[1];
		for(int i=2;i<=n;i++){
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
		cout<<len<<endl;
	}
	
	return 0;
}
