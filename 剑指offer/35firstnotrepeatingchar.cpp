#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin>>str;
	map<char,int> mp;
	for(int i=0;i<str.length();i++){
		mp[str[i]]++;
	} 
	for(int i=0;i<str.length();i++){
		if(mp[str[i]]==1) {
			cout<<str[i]<<endl;
			return 0;
		}
	}
	
	
	
	
	return 0;
}
/*
abaccdeff
*/
