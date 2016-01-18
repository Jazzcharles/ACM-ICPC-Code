#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a[10],ans=0,x;
	for(int i=0;i<10;i++){
		cin>>a[i];
		a[i]-=30;
	}
	cin>>x;
	for(int i=0;i<10;i++){
		if(x>=a[i])
		 ans++;
	}
	cout<<ans<<endl;
	return 0;
}
