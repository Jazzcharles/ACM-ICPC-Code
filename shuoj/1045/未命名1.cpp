#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int m=unique(a,a+n)-a;
	cout<<m<<endl;
	for(int i=0;i<m;i++){
		if(i)cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
