#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e5+500;

int a[maxn];
int b[maxn];
int dp[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m,k,t;
		cin>>n>>m>>k>>t;
		for(int i=0;i<m;i++) cin>>a[i];
		for(int i=0;i<m;i++) cin>>b[i];
		int ans=0,flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<maxn;j++) dp[j]=INF;
			dp[0]=0;
			for(int j=0;j<m;j++){
//				for(int p=b[j];p<=k;p++){
//					dp[p]=min(dp[p],dp[p-b[j]]+a[j]);
//				}
				for(int pre=0;pre<k;pre++){
					int cur=pre+b[j];
					if(cur>=k) dp[k]=min(dp[k],dp[pre]+a[j]);
					else dp[cur]=min(dp[cur],dp[pre]+a[j]);
				}
			}
			//cout<<ans<<' '<<dp[k]<<endl;
			if(dp[k]!=INF) ans+=dp[k];
			else {
				flag=1;
				break;
			}
			for(int j=0;j<m;j++) b[j]/=t;
		}
		if(flag) cout<<"No Answer"<<endl;
		else cout<<ans<<endl;
	}	
	
	
	
	return 0;
} 
/*
2
2 2 2 2
1 3
1 2
2 2 2 2
1 2
1 1
*/
