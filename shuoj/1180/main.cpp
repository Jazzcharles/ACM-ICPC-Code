#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin>>t;
	getchar();
	while(t--){
		int cnt=0;
		string s;
		getline(cin,s);
		string a(s),b(s);	
		reverse(a.begin(),a.end());
//		while(a!=b){
			cnt++;
			for(int i=s.length()-1;i>=0;i--)
				a[i]=a[i]+b[i];
			cout<<a<<endl;
//		}
	}
	return 0;
}
