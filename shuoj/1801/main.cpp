#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	long long a[10000];a[1]=a[2]=1;
	for(int i=3;i<=10000;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n,ca=1;
	while(cin>>n){
		printf("Case %d:%d,%d\n",ca++,n,a[n]);
	}
	return 0;
}
