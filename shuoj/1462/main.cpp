#include <bits/stdc++.h>
using namespace std;
bool ok(char a,char b){
	if(a=='(' && b==')' || a=='['&& b==']'|| a=='<'&& b=='>'|| a=='{'&& b=='}')
	  return 1;
	return 0;
}
int main()
{
	string s;
	while(cin>>s){
		int flag=1;
		stack<char>q;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('||s[i]=='['||s[i]=='<'||s[i]=='{' )
              q.push(s[i]);
            else
            {
            	if(q.empty())
                {
                  	flag=0;break;
				}
                else{	
					char ch=q.top();		
					if(ok(ch,s[i]))	
						q.pop();
					else{
						flag=0;break;
					}
			    }
			}
	    }
	    //cout<<q.empty()<<endl;
	    if(!q.empty()) flag=0;
	    if(!flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;			
	}	
	return 0;
}
