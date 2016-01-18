#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int a[50];
	a[0]=a[1]=1;
	for(int i=2;i<45;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i) cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
