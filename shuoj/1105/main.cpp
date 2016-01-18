#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	string a,b;
	getline(cin,a,'\n');
	b=a;reverse(a.begin(),a.end());
	b+=a;
	cout<<b<<endl;
	return 0;
}
