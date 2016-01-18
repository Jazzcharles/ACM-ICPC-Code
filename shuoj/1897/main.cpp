#include <bits/stdc++.h>
using namespace std;
int a[5050];
int main(int argc, char** argv) {
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int m=n*2;
		for(int i=1;i<=m;i++) cin>>a[i];
		sort(a+1,a+1+m);
		int s=0;
		for(int i=1;i<=m/2;i++) s+=(a[i]-a[m+1-i])*(a[i]-a[m+1-i]);
		cout<<s<<endl;
	}
	return 0;
}
