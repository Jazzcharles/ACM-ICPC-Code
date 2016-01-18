#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		if(i%2) ans+=i;  
	}
	cout<<ans<<endl;
	return 0;
}
