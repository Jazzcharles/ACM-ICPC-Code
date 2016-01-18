#include<iostream>
using namespace std;
int main()
{
	int a,b,i=1;
	cin>>a;
	b=a*a-a+1;
	cout<<a<<"*"<<a<<"*"<<a<<"="<<a*a*a<<"="<<b;
	for (i = 1; i < a; ++i) {
    cout << "+" << (b + 2*i);
	}
	cout<<endl;
	return 0;
}
