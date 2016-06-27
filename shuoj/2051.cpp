#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,ca=1;
	cin>>t;
	getchar();
	while(t--){
		string s;
		getline(cin,s);
		string ss=s;
		reverse(s.begin(),s.end());
		if(ss==s) printf("Case %d: YES.\n",ca++);
		else printf("Case %d: NO.\n",ca++);
	}
}
