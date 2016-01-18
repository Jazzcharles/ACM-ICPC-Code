#include <iostream>
using namespace std;
#define max(a,b) (a>b?a:b)
int main(int argc, char** argv) {
	string a;
	while(cin>>a){
		int ans=0;
		for(int i=0;a[i];i++){
			ans=max(a[i],ans);
		}
		for(int i=0;a[i];i++){
			cout<<a[i];
			if(a[i]==ans){
				cout<<"("<<"max"<<")";
			}
		}
		cout<<endl;
	}
	return 0;
}
