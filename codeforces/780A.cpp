#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+500;
int a[maxn];
int main(){
	int n;
	cin>>n;
	for(int i = 0 ; i < 2*n ; i++){
		cin>>a[i];
	}
	set<int> s;
	int ans = 0;
	for(int i = 0 ; i < 2*n ; i++){
		if(!s.count(a[i])){
			s.insert(a[i]);
			int num = s.size();
			ans = max(ans, num);
		}
		else s.erase(a[i]);
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
