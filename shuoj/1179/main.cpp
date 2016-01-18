#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	string a;
	getline(cin,a,'\n');
	string b=a;reverse(a.begin(),a.end());
	if(b==a) cout<<"Y"<<endl;
	else cout<<"N"<<endl;
	return 0;
}
