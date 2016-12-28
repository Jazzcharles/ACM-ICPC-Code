#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3;
int a[maxn];
int sum[maxn];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	while(m--){
		int l,r;
		cin>>l>>r;
		if(sum[r]-sum[l-1]>=0) ans+=sum[r]-sum[l-1];
	}
	cout<<ans<<endl;
	return 0;
}
/*


*/
