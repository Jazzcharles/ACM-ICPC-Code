#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	string a;
	while(cin>>a){
		string b=a;
		reverse(a.begin(),a.end());
		if(a==b) printf("YES!\n");
		else printf("NO!\n");
	}
	return 0;
}
