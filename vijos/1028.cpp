#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+5;
typedef pair<int,string> PIC;
PIC a[maxn];
int dp[maxn];

int main(){
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		cin>>a[i].second;
//		cout<<i<<' '<<a[i].second.length()<<endl;
		a[i].first=a[i].second.length();
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		dp[i]=1;
//		cout<<a[i].first<<' '<<a[i].second<<endl;
		for(int j=0;j<i;j++){
			if(a[i].second.find(a[j].second)==0)
				dp[i]++;
		}
//		cout<<dp[i]<<endl;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
