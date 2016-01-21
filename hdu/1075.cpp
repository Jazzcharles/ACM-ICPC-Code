#include<iostream>
#include<map>
#include<string> 
using namespace std;

int main(){
	map<string,string>m;
	string str1,str2;
	getline(cin,str1);
	while(cin>>str1 && str1!="END")
	{
		cin>>str2;
		m[str2]=str1;
	}
	getline(cin,str1);
	getline(cin,str1);
//	cout<<str1<<endl;
	while(getline(cin,str1) && str1!="END"){
		string temp;
		m[temp]="";
		for(int i=0;i<str1.length();i++){
			if(isalpha(str1[i])){
				temp+=str1[i];
			}
			else{
				if(m.count(temp)){
					cout<<m[temp]<<str1[i];
				} 
				else cout<<temp<<str1[i];
				temp="";
			}
		}
		cout<<endl;
	}
	return 0;
}
