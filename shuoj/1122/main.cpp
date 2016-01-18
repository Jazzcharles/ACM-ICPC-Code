#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n,f=0;cin>>n;
	for(int i=2;i<=n/2;i++){
		if(n%i==0) f=1;
	}
	if(f) cout<<0<<endl;
	else cout<<1<<endl;
	return 0;
}
