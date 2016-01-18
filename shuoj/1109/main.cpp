#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	string a;
	getline(cin,a,'\n');
	int cnt=0;
	for(int i=0;a[i];i++){
		if(isdigit(a[i]))
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
