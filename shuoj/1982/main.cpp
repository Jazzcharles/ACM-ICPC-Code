#include <iostream>
using namespace std;
const int maxn=1e5+5;
long long a[maxn];
int main(int argc, char** argv) {
	a[0]=0,a[1]=1;
	for(int i=2;i<=1000;i++)
		a[i]=a[i-1]+a[i-2];	
	int n,i;
	while(~scanf("%d",&n)){
		if(n==-1) break;
		for(i=0;i<=1000;i++){
			if(a[i]==n) break;
		}
		if(i>1000) printf("Not a Fibonacci number.\n");
		else printf("%d\n",i);
	}
	return 0;
}
