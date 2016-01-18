#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin>>t;
	getchar();
	while(t--)
	{
		string s;
		int flag=0,cnt=0;
		getline(cin,s);
		for(int i=0;i<s.length();i++){
			if(s[i]=='z'&&s[i+1]!='z'){
				flag++;
			}
			else if(s[i]=='z'){
				if(s[i-1]=='z'&&i==s.length()-1){
					cnt++;break;
				}
				else if(s[i+1]=='z'){
					cnt++;
				}
				flag=0;
			}
			if(flag==2){
				cnt++;
				flag=0;
			}
		}
		cout<<cnt<<endl;
	}

	return 0;
}
