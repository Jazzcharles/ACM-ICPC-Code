#include <iostream>
using namespace std;
int gcd(int a,int b){
	if(!b) return a;
	else gcd(b,a%b);
}

int main(int argc, char** argv) {
	int a,b;
	cin>>a>>b;
	cout<<a*b/gcd(a,b)<<endl;
	return 0;
}
