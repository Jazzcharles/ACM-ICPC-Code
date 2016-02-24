#include<iostream>
using namespace std;
int a[1005],q[1005],dp[1005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int len=1;
	q[1]=a[1];
	for(int i=2;i<=n;++i){
		int l=1,r=len;
		while(l<=r){
			int mid=(l+r)>>1;
			if(q[mid]<a[i])
				l=mid+1;
			else
				r=mid-1;
		}
		q[l]=a[i];
		dp[i]=l;
		len=max(len,l);
	}
	cout<<len<<endl;
	
	return 0;
}
