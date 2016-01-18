#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<(a+b)%100<<endl;
	}

	return 0;
}
