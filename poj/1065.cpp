#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int dp[maxn],q[maxn];
struct node{
	int x,y,id;
}a[maxn];
int cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y;
		}
		memset(dp,0,sizeof(dp));
		memset(q,0,sizeof(q)); 
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++) cout<<a[i].x<<' '<<a[i].y<<endl;	
//		for(int i=1;i<=n;i++){
//			dp[i]=1;
//			for(int j=i-1;j>=1;j--){
//				if(a[j].y>a[i].y){
//					dp[i]=max(dp[i],dp[j]+1);
//				}
//			}
//		}
		int len=1;
		q[1]=a[1].y;
		for(int i=2;i<=n;i++){
			int l=1,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(q[mid]>a[i].y)
					l=mid+1;//fanogoafetpumnighoostenid
				else
					r=mid-1;
			}
			q[l]=a[i].y;
			len=max(len,l);
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,dp[i]); 
	//	for(int i=1;i<=n;i++) cout<<dp[i]<<' ';cout<<endl;
	//	cout<<ans<<endl;
		cout<<len<<endl;
	}
	return 0;
}
