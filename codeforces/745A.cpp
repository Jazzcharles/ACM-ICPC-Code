#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin>>str;
	int n=str.length();
	set<string> s;
	for(int i=0;i<n;i++){
		string temp;
		for(int j=n-i;j<n;j++){
			temp+=str[j];
		}
		for(int j=0;j<n-i;j++){
			temp+=str[j];
		}
		//cout<<temp<<endl;
		s.insert(temp);
	} 
	cout<<s.size()<<endl;
	
	
	return 0;
}
/*
abcd

bbb

yzyz

*/
