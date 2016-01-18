#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int ca=1;
	string a,b;
	while(getline(cin,a)){
		stringstream ss;
		for(int i=0;a[i];i++){
			if(!isdigit(a[i])) a[i]=' ';
		}
		int n;
		ss<<a;
		cout<<"Case "<<ca++<<":"<<endl;
		ss>>b;
		for(int i=0;i<b.length();i++)
		{
			if(b[i]!='0')
			for(int j=i;j<b.length();j++)
				cout<<b[j];
			break;
		}	
		while(ss>>b){
			cout<<' ';
			for(int i=0;i<b.length();i++){
				if(b[i]!='0')
				for(int j=i;j<b.length();j++)
					cout<<b[j];
				break;
			}
			
		}
		ss.str("");b="";
		cout<<endl;
	}
	return 0;
}
