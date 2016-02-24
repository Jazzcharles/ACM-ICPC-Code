#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct node{
	int x,y;
}a[10005];
int dp[10005];

int cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x; 
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	memset(dp,INF,sizeof(dp));
	dp[1]=a[1].x+a[1].y-1;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i].x>a[j].x+a[j].y){
				dp[i]=min(dp[i],dp[j]+a[i].x+a[i].y-1);
			} 
		}
		cout<<dp[i]<<' ';
	}
	cout<<endl;
	int ans=INF;
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[i]);
	cout<<m-ans<<endl;
	return 0;
}
