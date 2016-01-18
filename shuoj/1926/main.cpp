#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int t;scanf("%d",&t);
	string a;
	while(t--){
		getchar();
		getline(cin,a,'\n');
		string b=a;
		reverse(a.begin(),a.end());
		cout<<a<<endl<<b<<endl;
		if(a==b) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
