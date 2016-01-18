#include <iostream>
using namespace std;
unsigned long long a[21],s;
int main(int argc, char** argv) {
	int n;
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]*i;
		s+=a[i];
	}	
	cout<<s<<endl;
	return 0;
}

