#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int m;cin>>m;
	double ans=1;
	for(int i=2;i<=m;i++){
		ans-=1.0/(i*i);
	}
	printf("%.6f",ans);
	return 0;
}
