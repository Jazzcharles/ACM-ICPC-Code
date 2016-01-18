#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int a[10],b[10];
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<9;i++){
			cin>>a[i];
		}
		int j=0;
		for(int i=8;i>=1;i--){
			if(a[i]<=a[0])
				b[j++]=a[i];
		}
		b[j++]=a[0];
		for(int i=1;i<=8;i++){
			if(a[i]>a[0])
				b[j++]=a[i];
		}
		for(int i=0;i<9;i++){
			if(i) cout<<' ';
			cout<<b[i];
		}
		cout<<endl;
		
	}
	return 0;
}
