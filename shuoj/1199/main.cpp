#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	int n,m,x;
	set<int>a;
	while(cin>>n>>m && (n || m)){
		for(int i=0;i<n;i++){
//			cin>>a[i];
 			cin>>x;
			a.insert(x);
		}
		int t=lower_bound(a.begin(),a.end(),m);
		for(int i=n+1;i>t;i--){
			a[i]=a[i-1];
		}
		a[t]=m;
		for(int i=0;i<n+1;i++){
			if(i) cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
