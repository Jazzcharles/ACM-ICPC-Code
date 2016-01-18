#include <bits/stdc++.h>
using namespace std;
int a[10000];

void f(){
	memset(a,0,sizeof(a));
	for(int i=2;i<=10000;i++){
		if(!a[i]){
			for(int j=i*i;j<=10000;j+=i)
				a[j]=1;
		}
	}
}
int main(int argc, char** argv) {
	int n;
	cin>>n;
	f();
	for(int i=2;i<=n;i++){
		if(!a[i])
			cout<<i<<' ';
	}
	return 0;
}
