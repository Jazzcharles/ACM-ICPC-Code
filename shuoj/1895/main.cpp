#include<bits/stdc++.h>
using namespace std;
#define pi 3.1415926
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		double rad=c*1.0/180*pi;
		printf("%.2f\n",sqrt(a*a+b*b+2*a*b*cos(rad)));
	}
	
	
	return 0;
}
