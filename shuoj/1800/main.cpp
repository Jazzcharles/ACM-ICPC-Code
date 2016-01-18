#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;cin>>n;
	while(n--){
		int t;
		cin>>t;
		if(t<=59) cout<<"E"<<endl;
		else if(t<=69) cout<<"D"<<endl;
		else if(t<=79) cout<<"C"<<endl;
		else if(t<=89) cout<<"B"<<endl;
		else cout<<"A"<<endl;
	}
	return 0;
}
