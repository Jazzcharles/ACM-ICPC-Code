#include <iostream>
using namespace std;
#include <stack>
#define REP(i,x) for(int i=0;i<x;i++)
bool judge(char a,char b){
	if(a=='(' && b==')' || a=='['&& b==']' || a=='<' && b=='>' || a=='{' && b=='}')
	  return 1;
	else 
	  return 0;
}
int main(int argc, char** argv) {
	char a[256];
	while(gets(a)){
		stack<char>s;
		int flag=1;
		REP(i,a[i]){
			if(a[i]=='{' || a[i]=='(' || a[i]=='[' || a[i]=='<')
		     s.push(a[i]);
		    else{
		    	if(s.empty()){
		    		flag=0;break;
				}
				else{
					if(judge(s.top(),a[i])){
						s.pop();
					}
					else{
						flag=1;break;
					}
				}
		    }	  
		}    	
		if(!s.empty()){
			flag=0;
		}    	
		if(!flag){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}	
		 
		
	}
	return 0;
}
