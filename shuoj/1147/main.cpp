#include <iostream>
using namespace std;
const int maxn=1e5;
double a[maxn],c[maxn];
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	scanf("%d%d",&a[0],&a[n+1]);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	return 0;
}
