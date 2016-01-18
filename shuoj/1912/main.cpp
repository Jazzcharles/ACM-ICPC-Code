#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int ans=0;
		while(a>b){	
			ans++;
			a-=a%(a/2+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
