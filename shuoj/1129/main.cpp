#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;cin>>n;
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=(double)1/i;
	}
	printf("%.6f",ans);
	return 0;
}
