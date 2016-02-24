#include<iostream>
#include<stack>
using namespace std;

int main(){
	string str;
	while(cin>>str && str!="end")
	{
		int len=str.length();
		stack<char> s,ss;
		int cnt=0,cntt=0;
		for(int i=0;i<len;i++){
			if(str[i]=='(') s.push(str[i]);
			if(str[i]=='[') ss.push(str[i]);
			if(str[i]==')' && !s.empty()){
				cnt++;s.pop();
			}
			if(str[i]==']' && !ss.empty()){
				cntt++;ss.pop();
			}
		}
		cout<<2*(cnt+cntt)<<endl; 
	}
	return 0;
} 
