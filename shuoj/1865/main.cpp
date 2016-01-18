#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	string a;
	int cnt=0;
	while(getline(cin,a)){
		for(int i=0;a[i];i++) a[i]=tolower(a[i]);
		int p=0;
		while((p=a.find("yaoge",p))!=string :: npos){
			cnt++;
//			cout<<p<<endl;
			p++;   		
		}
	}
	cout<<cnt<<endl;
	return 0;
}
